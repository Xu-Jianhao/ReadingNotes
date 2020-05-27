#include "apue.h"
#include <fcntl.h>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *  Describe :                                                                 *
 *              Create a contain empty file.
 *
 *  Author   :  Xu-Jianhao                                                     *
 *                              Biu Biu Biu !!!                                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

char    buf1[] = "abcdefghij";
char    buf2[] = "ABCDEFGHIJ";

int main(void)
{
    int     fd;

    if((fd = creat("/home/xjh/Space/git/ReadingNotes/unix/log/file.hole", FILE_MODE)) < 0)
        err_sys("Creat error");

    if(write(fd, buf1, 10) != 10)
        err_sys("buf1 write error");
    /* offset now = 10 */

    if(lseek(fd, 16384, SEEK_SET) == -1)
        err_sys("lseek erroe");
    /* offset now = 16384 */

    if(write(fd, buf2, 10) != 10)
        err_sys("buf2 write error");
    /* offset now = 16394 */

    exit(0);
}

