/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *    Describe :                                                               *
 *          abort函数按POSIX.1说明实现
 *
 *    Author   :  Xu-Jianhao                                                   *
 *                               Biu Biu Biu !!!                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void abort(void)
{
    sigset_t          mask;
    struct sigaction  action;

    /* Caller can't ignore SIGABRT, if so reset to default */
    sigaction(SIGABRT, NULL, &action);          /* 获取现有的信号处理方式 */
    if(action.sa_handler == SIG_IGN) {          
        action.sa_handler = SIG_DFL;            /* 若现有处理方式是忽略,则设置为默认并设置回去 */
        sigaction(SIGABRT, &action, NULL);
    }

    if(action.sa_handler == SIG_DFL)            /* 若是默认处理方式则冲洗所有标准I/O流 */
        fflush(NULL);                   /* flush all open stdio streams */

    /* Caller can't block SIGABRT; make sure it's unblocked */
    sigfillset(&mask);
    sigdelset(&mask, SIGABRT);          /* mask has only SIGABRT turned off */

    sigprocmask(SIG_SETMASK, &mask, NULL);
    kill(getpid(), SIGABRT);            /* send the signal */

    /* If we're here, process caught SIGABRT and returned */
    fflush(NULL);                       /* flush all open stdio streams */
    action.sa_handler = SIG_DFL;
    sigaction(SIGABRT, &action, NULL);  /* reset to default */
    sigprocmask(SIG_SETMASK, &mask, NULL);  /* just in case ... */
    kill(getpid(), SIGABRT);                /* and one more time */

    exit(1);                    /* this should never be executed ... */
}
