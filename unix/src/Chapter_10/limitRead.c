/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *    Describe :                                                               *
 *          带时间限制的read函数
 *          使用alarm函数来给慢速系统调用的阻塞时间定时
 *
 *    Author   :  Xu-Jianhao                                                   *
 *                               Biu Biu Biu !!!                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*
 * 该程序存在的问题:
 *  1.  在第一次alarm调用和read调用之间存在竞争条件(CPU可能发生进程切换),在超过alarm定时时间之后才调用read
 *
 *  2.  如果系统调用是自动重启的,则当从SIGALRM信号处理程序中返回时,read被重新调用,这种情形下,设置时间限制没有意义
 */

#include "apue.h"

static void sig_alrm(int);

int main(void)
{
    int     n;
    char    line[MAXLINE];

    if(signal(SIGALRM, sig_alrm) == SIG_ERR)
        err_sys("signal(SIGALRM) error");

    alarm(10);
    if((n = read(STDIN_FILENO, line, MAXLINE)) < 0)
        err_sys("read error");
    alarm(0);

    write(STDOUT_FILENO, line, n);
    exit(0);
}

static void sig_alrm(int signo)
{
    /* nothing to do, just return to interrupt the read */
}

