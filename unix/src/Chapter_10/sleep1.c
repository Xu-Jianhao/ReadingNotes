/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *    Describe :                                                               *
 *          使用alarm 和 pause 使进程自己休眠一段指定的时间
 *
 *    Author   :  Xu-Jianhao                                                   *
 *                               Biu Biu Biu !!!                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <signal.h>
#include <unistd.h>

static void sig_alrm(int signo)
{
    /* nothing to do, just return to wake up the pause */
}

unsigned int sleep1(unsigned int seconds)
{
    if(signal(SIGALRM, sig_alrm) == SIG_ERR)
        return(seconds);
    alarm(seconds);         /* start the timer */
    pause();                /* next caught signal wakes us up */
    return(alarm(0));       /* turn off timer, return unslept time */

    /*
     * 此函数存在的3个问题:
     *   1. 如果在调用sleep1之前,调用者已经设置了闹钟,则已设置的闹钟会被sleep1函数中的第一次alarm调用擦除
     *      解决办法:检查第一次调用alarm的返回值,如果返回值小于本次调用alarm的参数值,则应等待已有闹钟超时
     *              若返回值大于本次调用的seconds值,则在sleep1返回之前,重置此闹钟,使其之前的超时时间再次生效
     *   2. 该程序中修改了对SIGALRM的配置(捕捉),如果编写了一个函数供其他函数调用,则在该函数被调用时要先保存原有
     *      配置(信号集),在该函数返回前再恢复原配置
     *      解决办法:保存signal函数的返回值,在返回之前重置原配置
     *   3. 在第一次调用alarm和pause之间有一个竞争条件,在一个繁忙的系统中,可能alarm再调用pause之前超时,并调用了
     *      信号处理程序,则在调用pause之后,进程将被永久挂起
     *      解决办法: a.使用setjmp(见sleep2.c测试程序) b.使用sigprocmask和sigsupend (见10.19测试程序)
     */
}


int main(void)
{

    exit(0);
}

