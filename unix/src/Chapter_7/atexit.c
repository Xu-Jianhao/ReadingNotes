/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *  Describe :                                                                 *
 *          atexit function Example.
 *
 *  Author   :  Xu-Jianhao                                                     *
 *                              Biu Biu Biu !!!                                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "apue.h"

static void my_exit1(void);
static void my_exit2(void);

int main(void)
{
    if(atexit(my_exit2) != 0)
        err_sys("can't register my_exit2");

    if(atexit(my_exit1) != 0)
        err_sys("can't register my_exit1");
    if(atexit(my_exit1) != 0)
        err_sys("can't register my_exit1");

    printf("mian is done\n");
    /* exit(0); */
    return 0;
}

static void my_exit1(void)
{
    printf("First exit handler\n");
}

static void my_exit2(void)
{
    printf("Second exit handler\n");
}
