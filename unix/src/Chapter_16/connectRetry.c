/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *    Describe :                                                               *
 *          支持重试的connect函数实现.
 *
 *    Author   :  Xu-Jianhao                                                   *
 *                               Biu Biu Biu !!!                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "apue.h"
#include <sys/socket.h>

#define MAXSLEEP 128

int connect_retry(int sockfd, const struct sockaddr *addr, socklen_t alen)
{
    int numsec;

    /* Try to connect with exponential backoff. */
    for(numsec = 1; numsec <= MAXSLEEP; numsec <<= 1) {
        if(connect(sockfd, addr, alen) == 0) {
            /* Connection accepted. */
            return(0);
        }
        
        /* Delay before trying again. */
        if(numsec <= MAXSLEEP/2)
            sleep(numsec);
    }

    return(-1);
}
/*
 * 指数补偿算法(exponential backoff):
 *      如果调用connect失败,进程会休眠一小段时间,然后进入下次循环再次尝试,
 *      每次循环休眠时间会以指数级增加,直到最大延迟为2分钟左右.
 */
