#include "apue.h"
#include <fcntl.h>
#include <string.h>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *  Describe :                                                                 *
 *          Test unlink function.
 *          在程序运行阶段,链接计数为0的文件不会被删除
 *
 *  Author   :  Xu-Jianhao                                                     *
 *                              Biu Biu Biu !!!                                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int main(void)
{
    int     fd;
    char    buf[1024] = "";

    if((fd = open("/home/xjh/Space/git/ReadingNotes/unix/tempfile", O_RDWR)) < 0)
        err_sys("open error");
    if(unlink("/home/xjh/Space/git/ReadingNotes/unix/tempfile") < 0)
        err_sys("unlink error");
    printf("file unlinked\n");

    sleep(5);

    if(read(fd, buf, sizeof(buf)) <= 0)
        err_sys("read error");

    if(write(1 ,buf,strlen(buf)) < 0)
        err_sys("write error");

    printf("Done!\n");

    exit(0);
}

