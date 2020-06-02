#include "apue.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *  Describe :                                                                 *
 *          getc 和 putc 将标准输入复制到标准输出
 *
 *  Author   :  Xu-Jianhao                                                     *
 *                              Biu Biu Biu !!!                                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int main(void)
{
    int     c;

    while((c = getc(stdin)) != EOF)
        if(putc(c, stdout) == EOF)
            err_sys("output error");

    if(ferror(stdin))
        err_sys("input error");

    exit(0);
}

