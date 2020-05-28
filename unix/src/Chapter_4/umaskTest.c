#include "apue.h"
#include <fcntl.h>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *  Describe :                                                                 *
 *          Test umask function.
 *
 *  Author   :  Xu-Jianhao                                                     *
 *                              Biu Biu Biu !!!                                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main(void)
{
    umask(0);
    if(creat("/home/xjh/Space/git/ReadingNotes/unix/log/foo", RWRWRW) < 0)
        err_sys("creat error for foo");
    
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    
    if(creat("/home/xjh/Space/git/ReadingNotes/unix/log/bar", RWRWRW) < 0)
        err_sys("creat error for bar");

    exit(0);
}

