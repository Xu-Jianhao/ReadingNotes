#include "apue.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *  Describe :                                                                 *
 *          Test chmod function.
 *
 *  Author   :  Xu-Jianhao                                                     *
 *                              Biu Biu Biu !!!                                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int main(void)
{
    struct stat statbuf;

    /* turn on set-group-ID and turn off group-execute */

    if(stat("/home/xjh/Space/git/ReadingNotes/unix/log/foo", &statbuf) < 0)
        err_sys("stat error for foo");

    if(chmod("/home/xjh/Space/git/ReadingNotes/unix/log/foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID)<0)
        err_sys("chmod error for foo");

    /* set absolute mode to "rw-r--r--" */
    if(chmod("/home/xjh/Space/git/ReadingNotes/unix/log/bar", S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH) < 0)
        err_sys("chmod error for bar");

    exit(0);
}

