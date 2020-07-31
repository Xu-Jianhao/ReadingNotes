/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *    Describe :                                                               *
 *          可重试connect函数的可移植版本.
 *          因为在基于BSD的套接字实现中,如果connect失败,套接字的状态会
 *          变成未定义的.因此,如果connect失败,需要关闭套接字,如果想重试
 *          必须重新打开一个新的套接字。
 *
 *    Author   :  Xu-Jianhao                                                   *
 *                               Biu Biu Biu !!!                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "apue.h"
#include <sys/socket.h>

#define MAXSLEEP 128

int connect_retry(int domain, int type, int protocol, const struct sockaddr *addr, socklen_t alen)
{
    int numsec, fd;

    /* Try to connect with exponential backoff. */
    for(numsec = 1; numsec <= MAXSLEEP; numsec <<= 1) {
        if((fd = socket(domain, type, protocol)) < 0)
            return(-1);
        if(connect(fd, addr, alen) == 0) {
            /* Connection accepted. */
            return(fd);
        }
        close(fd);

        /* Delay before trying again. */
        if(numsec <= MAXSLEEP/2)
            sleep(numsec);
    }
    return(-1);
}

