#include "apue.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *  Describe :                                                                 *
 *      Function chdir and getcwd test!
 *
 *  Author   :  Xu-Jianhao                                                     *
 *                              Biu Biu Biu !!!                                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int main(void)
{
    char *ptr;
    size_t size;
    ptr = path_alloc(&size);

    if(getcwd(ptr, size) == NULL)
        err_sys("getcwd failed");

    printf("cwd = %s\n", ptr);

    if(chdir("/home/xjh/Space/") < 0)
        err_sys("chdir failed");

    if(getcwd(ptr, size) == NULL)
        err_sys("getcwd failed");

    printf("cwd = %s\n", ptr);

    exit(0);
}

