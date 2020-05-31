#include "apue.h"
#include <dirent.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *  Describe :                                                                 *
 *          递归降序遍历目录层次结构,并按文件类型计数
 *
 *  Author   :  Xu-Jianhao                                                     *
 *                              Biu Biu Biu !!!                                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* function type that is called for each filename */
typedef int Myfunc(const char *, const struct stat *, int);     /* 定义了一种函数指针类型 */

/* int myfunc(const char *, const struct stat *, int) */
static Myfunc myfunc;
static int  myftw(char *, Myfunc *);
static int  dopath(Myfunc *);
static long nreg, ndir, nblk, nchr, nfifo, nslink, nsock, ntot;

int main(int argc, char *argv[])
{
    int     ret;
    if(argc != 2)
        err_quit("usage: ./foreachDir [starting-pathname]");

    ret = myftw(argv[1], myfunc);       /* does it all */
    ntot = nreg + ndir + nblk + nchr + nfifo + nslink + nsock;
    if(ntot == 0)
        ntot = 1;                       /* avoid divide by 0; print 0 for all counts */

    printf("Regular files    = %7ld, %5.2f %%\n", nreg, nreg*100.0/ntot);
    printf("Directories      = %7ld, %5.2f %%\n", ndir, ndir*100.0/ntot);
    printf("Block Special    = %7ld, %5.2f %%\n", nblk, nblk*100.0/ntot);
    printf("Char Special     = %7ld, %5.2f %%\n", nchr, nchr*100.0/ntot);
    printf("FIFOs            = %7ld, %5.2f %%\n", nfifo, nfifo*100.0/ntot);
    printf("Symbolic Links   = %7ld, %5.2f %%\n", nslink, nslink*100.0/ntot);
    printf("Sockets          = %7ld, %5.2f %%\n", nsock, nsock*100.0/ntot);

    exit(ret);
}

/*
 * Descend through the hierarchy, starting at "pathname".
 * The caller's func() is called for every file.
 * */

#define FTW_F 1         /* file other than directory */
#define FTW_D 2         /* directory */
#define FTW_DNR 3       /* directory than can't be read */
#define FTW_NS 4        /* file that we can't stat */

static char *fullpath;  /* contains full pathname for every file */
static size_t pathlen;

static int myftw(char *pathname, Myfunc *func)
{
    fullpath = path_alloc(&pathlen);        /* malloc PATH_MAX+1 bytes */

    if(pathlen <= strlen(pathname)) {
        pathlen = strlen(pathname) * 2;
        if((fullpath = realloc(fullpath, pathlen)) == NULL)
            err_sys("realloc failed");
    }
    strcpy(fullpath, pathname);
    return(dopath(func));
}

/*
 * Descend through the hierarchy, starting at "fullpath".
 * If "fullpath" is anything other than a directory, we lstat() it,
 * call func(), and return. For a directory, we call ourself
 * recursively for each name in th directory.
 * */

static int dopath(Myfunc *func)     /* We return whatever func() returns */
{
    struct stat     statbuf;
    struct dirent   *dirp;
    DIR             *dp;
    int             ret, n;

    if(lstat(fullpath, &statbuf) < 0)   /* stat error */
        return(func(fullpath, &statbuf, FTW_NS));
    if(S_ISDIR(statbuf.st_mode) == 0)   /* not a directory */
        return(func(fullpath, &statbuf, FTW_F));

    /*
     * It's a directory. Fist call func() for the directory,
     * then process each filename in the directory.
     * */
    if((ret == func(fullpath, &statbuf, FTW_D)) != 0)
        return(ret);
    n = strlen(fullpath);
    if(n + NAME_MAX + 2 > pathlen) {    /* expand path buffer */
        pathlen *= 2;
        if((fullpath = realloc(fullpath, pathlen)) == NULL)
            err_sys("realloc failed");
    }
    fullpath[n+1] = '/';
    fullpath[n] = 0;
    if((dp = opendir(fullpath)) == NULL)    /* Can't read directory */
        return(func(fullpath, &statbuf, FTW_DNR));
    while((dirp = readdir(dp)) != NULL) {
        if(strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
            continue;
        strcpy(&fullpath[n], dirp->d_name);     /* append name after "/" */
        if((ret = dopath(func)) != 0)
            break;  /* time to leave */
    }
    fullpath[n-1] = 0;      /* erase everything from slash onward */
    if(closedir(dp) < 0)
        err_ret("Can't close directory %s", fullpath);
    return(ret);
}

static int myfunc(const char *pathname, const struct stat *statptr, int type)
{
    switch(type) {
        case FTW_F:
            switch(statptr->st_mode & __S_IFMT) {
                case __S_IFREG:
                    nreg++;
                    break;
                case __S_IFBLK:
                    nblk++;
                    break;
                case __S_IFCHR:
                    nchr++;
                    break;
                case __S_IFIFO:
                    nfifo++;
                    break;
                case __S_IFLNK:
                    nslink++;
                    break;
                case __S_IFSOCK:
                    nsock++;
                    break;
                case __S_IFDIR:
                    err_dump("for S_IFDIR for %s", pathname);
            }
            break;
        case FTW_D:
            ndir++;
            break;
        case FTW_DNR:
            err_ret("stat error for %s", pathname);
            break;
        default:
            err_dump("unknow type %d for pathname %s", type, pathname);
    }
    return(0);
}
