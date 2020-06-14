/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *    Describe :                                                               *
 *         解决sleep1.c中的第3个问题 
 *         在执行了pause挂起进程之后,pause可被SIGINT信号或SIGALRM信号唤醒
 *         当在执行SIGINT信号处理函数期间,收到SIGALRM信号,则SIGINT信号的
 *         处理函数会被直接中断;
 *
 *    Author   :  Xu-Jianhao                                                   *
 *                               Biu Biu Biu !!!                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <setjmp.h>
#include <signal.h>
#include <unistd.h>
#include "apue.h"

static jmp_buf env_alrm;
static void sig_int(int);

static void sig_alrm(int signo)
{
    longjmp(env_alrm, 1);
}

unsigned int sleep2(unsigned int seconds)
{
    if(signal(SIGALRM, sig_alrm) == SIG_ERR)
        return(seconds);
    if(setjmp(env_alrm) == 0) {
        printf("%s\n", __FUNCTION__);
        alarm(seconds);         /* start the timer */
        pause();                /* next caught signal wakes us up */
    }

    return(alarm(0));           /* turn off timer, return unslept time */
}

int main(void)
{
    unsigned int unslept;
    if(signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("signal(SIGINT) error");

    unslept = sleep2(5);
    printf("sleep2 returned: %u\n", unslept);
    exit(0);
}

static void sig_int(int signo)
{
    int          i,j;
    volatile int k;

    /*
     * Tune these loops to run for more than 5 seconds 
     * on whatever system this test program is run.
     */
    printf("\nsig_int starting\n");
    for(i = 0; i < 300000; i++)
        for(j = 0; j < 40000; j++)
            k += i * j;
    printf("sig_int finished\n");
}
