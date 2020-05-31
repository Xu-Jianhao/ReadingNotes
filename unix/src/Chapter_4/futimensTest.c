#include "apue.h"
#include <fcntl.h>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *  Describe :                                                                 *
 *          使用带O_TRUNC选项的open函数将文件长度截断为0,但是并不更改其访问    *
 *      时间及修改时间.                                                        *
 *          1、 首先使用stat函数得到未截断之前的时间.                          *
 *          2、 截断文件,最后利用futimens函数重置这两个时间                    *
 *  Author   :  Xu-Jianhao                                                     *
 *                              Biu Biu Biu !!!                                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int main(int argc, char *argv[])
{
    int             i,fd;
    struct stat     statbuf;
    struct timespec times[2];

    if(argc < 2)
        err_quit("usage: futimens [filename1] [filename2] ...");

    for(i = 1; i < argc; i++) {
        if(stat(argv[i], &statbuf) < 0) {   /* fetch current times */
            err_ret("%s: stat error", argv[i]);
            continue;
        }
        if((fd = open(argv[i], O_RDWR | O_TRUNC)) < 0) {    /* truncate */
            err_ret("%s: open error", argv[i]);
            continue;
        }
        times[0].tv_sec = statbuf.st_atime;
        times[0].tv_nsec = 0;
        times[1].tv_sec = statbuf.st_mtime;
        times[1].tv_nsec = 0;
        if(futimens(fd, times) < 0)     /* reset times */
            err_ret("%s: futimens error", argv[i]);

        close(fd);
    }

    exit(0);
}

