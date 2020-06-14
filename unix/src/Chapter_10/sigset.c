/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *    Describe :                                                               *
 *          sigaddset、sigdelset 和 sigismember 的实现
 *
 *    Author   :  Xu-Jianhao                                                   *
 *                               Biu Biu Biu !!!                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <signal.h>
#include <errno.h>

/* 判断信号是否存在 */
#define SIGBAD(signo)((signo) <= 0 || (signo) >= NSIG)

int sigaddset(sigset_t *set, int signo)
{
    if(SIGBAD(signo)) {
        errno = EINVAL;
        return(-1);
    }

    *set |= 1 << (signo - 1);       /* turn bit on */
    return(0);
}

int sigdelset(sigset_t *set, int signo)
{
    if(SIGBAD(signo)) {
        errno = EINVAL;
        return(-1);
    }

    *set &= ~(1 << (signo - 1));    /* turn bit off */
    return(0);
}

int sigismember(const sigset_t *set, int signo)
{
    if(SIGBAD(signo)) {
        errno = EINVAL;
        return(-1);
    }

    return((*set & (1 << (signo - 1))) != 0);
}

int main(void)
{

    exit(0);
}

