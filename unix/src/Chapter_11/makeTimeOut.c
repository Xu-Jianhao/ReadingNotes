/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *    Describe :                                                               *
 *          获取超时值的绝对时间函数
 *
 *    Author   :  Xu-Jianhao                                                   *
 *                               Biu Biu Biu !!!                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>

void maketimeout(struct timespec *tsp, long minutes)
{
    struct timeval now;

    /* get the current time */
    gettimeofday(&now, NULL);
    tsp->tv_sec  = now.tv_sec;
    tsp->tv_nsec = now.tv_usec * 1000;  /* usec to nsec */
    /* add the offset to get timeout value */
    tsp->tv_sec += minutes * 60;
}

int main(void)
{
    struct timespec time_n;
    maketimeout(&time_n, 10);

    printf("10 minutes after: %d - %d \n", (int)time_n.tv_sec, (int)time_n.tv_nsec);

    exit(0);
}

