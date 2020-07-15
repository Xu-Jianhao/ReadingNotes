/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *    Describe :                                                               *
 *          <apue.h>中的一些函数实现
 *
 *    Author   :  Xu-Jianhao                                                   *
 *                               Biu Biu Biu !!!                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "apue.h"
#include <fcntl.h>

static volatile sig_atomic_t sigflag;       /* set nonzero by sig handler */
static sigset_t newmask, oldmask, zeromask;

static void sig_usr(int signo)              /* one signal handler for SIGUSR1 and SIGUSR2 */
{
    sigflag = 1;
}

void TELL_WAIT(void)
{
    if(signal(SIGUSR1, sig_usr) == SIG_ERR)
        err_sys("signal(SIGUSR1) error");

    if(signal(SIGUSR2, sig_usr) == SIG_ERR)
        err_sys("signal(SIGUSR2) error");

    sigemptyset(&zeromask);
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGUSR1);
    sigaddset(&newmask, SIGUSR2);

    /* Block SIGUSR1 and SIGUSR2, and save current signal mask */
    if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
        err_sys("SIG_BLOCK error");
}

void TELL_PARENT(pid_t pid)
{
    kill(pid, SIGUSR2);         /* tell parent we're done */
}

void WAIT_PARENT(void)
{
    while(sigflag == 0)
        sigsuspend(&zeromask);  /* and wait for parent */
    sigflag = 0;

    /* Reset signal mask to original value */
    if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
        err_sys("SIG_SETMASK error");
}

void TELL_CHILD(pid_t pid)
{
    kill(pid, SIGUSR1);         /* tell child we're done */
}

void WAIT_CHILD(void)
{
    while(sigflag == 0)
        sigsuspend(&zeromask);  /* adn wait for child */
    sigflag = 0;

    /* Reset signal mask to orignal value */
    if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
        err_sys("SIG_SETMASK error");
}

/* 设置文件描述符在执行时关闭. */
int set_cloexec(int fd)
{
    int     val;
    
    if((val = fcntl(fd, F_GETFD, 0)) < 0)
        return(-1);

    val |= FD_CLOEXEC;      /* enable close-on-exec */

    return(fcntl(fd, F_SETFD, val));
}

/* Set File status flags */
/* 对一个文件描述符开启一个或多个文件状态标志 */
void set_fl(int fd, int flags)
{
    int val;

    if((val = fcntl(fd, F_GETFL, 0)) < 0)
        err_sys("fcntl F_GETFL error");

    val |= flags;       /* turn on flags */

    if(fcntl(fd, F_SETFL, val) < 0)
        err_sys("fcntl F_SETFL error");
}

/* 记录锁,函数避免加锁解锁时每次分配flock结构 */
/* 加锁或解锁一个文件区域的函数 */
int lock_reg(int fd, int cmd, int type, off_t offset, int whence, off_t len)
{
    struct flock lock;

    lock.l_type     = type;         /* F_RDLCK, F_WRLCK, F_UNLCK */
    lock.l_start    = offset;       /* byte offset, relative to l_whence */
    lock.l_whence   = whence;       /* SEEK_SET, SEEK_CUR, SEEK_END */
    lock.l_len      = len;          /* #bytes (0 means to EOF) */

    return(fcntl(fd, cmd, &lock));
}

/* 用来测试一把记录锁 */
pid_t lock_test(int fd, int type, off_t offset, int whence, off_t len)
{
    struct flock lock;

    lock.l_type     = type;         /* F_EDLCK or F_WRLCK */
    lock.l_start    = offset;       /* byte offset, relative to l_whence */
    lock.l_whence   = whence;
    lock.l_len      = len;

    if(fcntl(fd, F_GETLK, &lock) < 0)
        err_sys("fcntl error");

    if(lock.l_type == F_UNLCK)
        return(0);                  /* false, region isn't locked by another proc */
    return(lock.l_pid);             /* true, return pid of lock owner */
}


/* Read "n" bytes from a descriptor */
ssize_t readn(int fd, void *ptr, size_t n)
{
    size_t  nleft;
    ssize_t nread;

    nleft = n;
    while(nleft > 0) {
        if((nread = read(fd, ptr, nleft)) < 0) {
            if(nleft == n)
                return(-1);     /* error, return -1 */
            else
                break;          /* error, return amount read so far */
        } else if(nread == 0) {
            break;      /* EOF */
        }
        nleft -= nread;
        ptr += nread;
    }
    return(n - nleft);  /* return >= 0 */
}

/* Write "n" bytes to a descriptor */
ssize_t writen(int fd, const void *ptr, size_t n)
{
    size_t  nleft;
    ssize_t nwritten;

    nleft = n;
    while(nleft > 0) {
        if((nwritten = write(fd, ptr, nleft)) < 0) {
            if(nleft == n)
                return(-1);         /* error, return -1 */
            else
                break;              /* error, return amount written so far */
        } else if(nwritten == 0) {
            break;
        }
        nleft -= nwritten;
        ptr += nwritten;
    }
    return(n - nleft);      /* return >= 0 */
}


