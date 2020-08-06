/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *    Describe :                                                               *
 *          示例将一个地址绑定到UNIX域套接字.
 *
 *    Author   :  Xu-Jianhao                                                   *
 *                               Biu Biu Biu !!!                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "apue.h"
#include <sys/socket.h>
#include <sys/un.h>

int main(void)
{
    int     fd, size;
    struct sockaddr_un un;

    un.sun_family = AF_UNIX;
    strcpy(un.sun_path, "foo.socket");
    if((fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
        err_sys("sock failed");
    

    /* 
     * 确定绑定地址长度的方法是,先计算sun_path成员在sockaddr_un结构中的偏移量,
     * 然后将结果与路径名长度(不包括终止null字符)相加
     */
    size = offsetof(struct sockaddr_un, sun_path) + strlen(un.sun_path);
    if(bind(fd, (struct sockaddr *)&un, size) < 0)
        err_sys("bind failed");

    printf("UNIX domain socker bound\n");

    /* unlink("foo.socket"); */     /* 不删除socket文件，下次绑定会失败！ */

    exit(0);
}

