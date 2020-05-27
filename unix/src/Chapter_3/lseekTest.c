#include "apue.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *  Describe :                                                                 *
 *              Test STDIN Whether set lseek.
 *              ./lseekTest < fileName              重定向标准输入到文件
 *              cat < /etc/passwd | ./lesskTest     重定向标准输入到终端
 *              ./lseekTest < /var/spool/cron/FIFO  重定向标准输入到管道
 *  Author   :  Xu-Jianhao                                                     *
 *                              Biu Biu Biu !!!                                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int main(void)
{
    if(lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
        printf("Can't seek!\n");
    else
        printf("Seek OK!\n");

    exit(0);
}

