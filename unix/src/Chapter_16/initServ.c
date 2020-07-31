/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *    Describe :                                                               *
 *          初始化一个套接字端点供服务器进程使用.
 *
 *    Author   :  Xu-Jianhao                                                   *
 *                               Biu Biu Biu !!!                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "apue.h"
#include <errno.h>
#include <sys/socket.h>

int initserver(int type, const struct sockaddr *addr, socklen_t alen, int qlen)
{
    int fd, err;
    int reuse = 1;

    if((fd = socket(addr->sa_family, type, 0)) < 0)
        return(-1);
    if(setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int)) < 0)
        goto errout;
    if(bind(fd, addr, alen) < 0)
        goto errout;
    if(type == SOCK_STREAM || type ==SOCK_SEQPACKET)
        if(listen(fd, qlen) < 0)
            goto errout;

    return(fd);

errout:
    err = errno;
    close(fd);
    errno = err;
    return(-1);
}



/*
 *  此版本在服务器终止并尝试立即重启时,将无法正常工作。
 *  通常情况下,除非超时(超时时间一般是几分钟),否则TCP的实现不允许绑定同一个地址。
 *  可以使用套接字选项SO_REUSEADDR绕过这个限制。
 */
/*
int initserver(int type, const struct sockaddr *addr, socklen_t alen, int qlen)
{
    int fd;
    int err = 0;

    if((fd = socket(addr->sa_family, type, 0)) < 0)
        return(-1);
    
    if(bind(fd, addr, alen) < 0)
        goto errout;

    if(type == SOCK_STREAM || type == SOCK_SEQPACKET) {
        if(listen(fd, qlen) < 0)
            goto errout;
    }
    return(fd);

errout:
    err = errno;
    close(fd);
    errno = err;
    return(-1);
}
*/
