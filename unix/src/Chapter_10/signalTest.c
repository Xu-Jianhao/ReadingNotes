/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *    Describe :                                                               *
 *          一个简单的信号处理程序,它捕捉两个用户定义的信号并打印信号编号
 *
 *    Author   :  Xu-Jianhao                                                   *
 *                               Biu Biu Biu !!!                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "apue.h"

static void sig_usr(int);       /* one handler for both signals */

int main(void)
{
    if(signal(SIGUSR1, sig_usr) == SIG_ERR)
        err_sys("Can't catch SIGUSR1");
    if(signal(SIGUSR2, sig_usr) == SIG_ERR)
        err_sys("Can't catch SIGUSR2");

    for( ; ; )
        pause();                /* 挂起等待信号的到来 */

    exit(0);
}

static void sig_usr(int signo)
{
    if(signo == SIGUSR1)
        printf("received SIGUSR1\n");
    else if(signo == SIGUSR2)
        printf("received SIGUSR2\n");
    else
        err_dump("received signal %d\n", signo);
}

