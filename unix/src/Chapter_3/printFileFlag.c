#include "apue.h"
#include <fcntl.h>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *  Describe :                                                                 *
 *              Print a file describe flage 
 *
 *  Author   :  Xu-Jianhao                                                     *
 *                              Biu Biu Biu !!!                                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


extern void set_fl(int, int);

int main(int argc, char *argv[])
{
    int     val;

    if(argc != 2)
        err_quit("usage: ./printFileFlag <descriptor#>");

    if((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
        err_sys("fcntl error for fd %d", atoi(argv[1]));

    switch(val & O_ACCMODE) {
    case O_RDONLY:
        printf("Read Only");
        break;

    case O_WRONLY:
        printf("Write Only");
        break;

    case O_RDWR:
        printf("Read Write");
        break;

    default:
        err_dump("unknown accsee mode");
    }

    if(val & O_APPEND)
        printf(", Append");
    if(val & O_NONBLOCK)
        printf(", nonblocking");
    if(val & O_SYNC)
        printf(", synchronous writes");

#if !defined(_POSIX_C_SOUCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
    if(val & O_FSYNC)
        printf(", synchronous writes");
#endif

    putchar('\n');
    exit(0);
}

