/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *  Describe :                                                                 *
 *          print environ
 *
 *  Author   :  Xu-Jianhao                                                     *
 *                              Biu Biu Biu !!!                                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "apue.h"

int main(void)
{
    printf("PID: %d\n", getpid());
    printf("终端宽度:   %s\n", getenv("COLUMNS"));
    printf("终端高度:   %s\n", getenv("LINES"));
    printf("起始目录:   %s\n", getenv("HOME"));
    printf("LANG:       %s\n", getenv("LANG"));
    printf("LC_COLLATE: %s\n", getenv("LC_COLLATE"));
    printf("登录名:     %s\n", getenv("LOGNAME"));
    printf("终端类型:   %s\n", getenv("TERM"));
    printf("工作目录:   %s\n", getenv("PWD"));
    printf("时区信息:   %s\n", getenv("TZ"));

    exit(0);
}

