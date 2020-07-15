/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *    Describe :                                                               *
 *          非阻塞I/O的实例
 *          从标准输入读500000字节,并试图将它们写到标准输出上
 *          该程序先将标准输出设置为非阻塞的,然后用for循环进行输出,
 *          每次write调用的结果都在标准错误上打印.
 *
 *    Author   :  Xu-Jianhao                                                   *
 *                               Biu Biu Biu !!!                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "apue.h"
#include <errno.h>
#include <fcntl.h>

char buf[500000];

int main(void)
{
    int     ntowrite, nwrite;
    char    *ptr;

    ntowrite = read(STDIN_FILENO, buf, sizeof(buf));
    fprintf(stderr, "read %d bytes\n", ntowrite);

    set_fl(STDOUT_FILENO, O_NONBLOCK);      /* set nonblocking */

    ptr = buf;
    while(ntowrite > 0) {
        errno = 0;
        nwrite = write(STDOUT_FILENO, ptr, ntowrite);
        fprintf(stderr, "nwrite = %d, errno = %d\n", nwrite, errno);

        if(nwrite > 0) {
            ptr += nwrite;
            ntowrite -= nwrite;
        }
    }

    exit(0);
}

