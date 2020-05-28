#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *  Describe :                                                                 *
 *              Test O_APPEND lseek
 *  Result :
 *              Read Success!
 *              Write Faild!
 *  Author   :  Xu-Jianhao                                                     *
 *                              Biu Biu Biu !!!                                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

char    buf[] = "XJH Want To Go To Alicloud!!";

int main(void)
{
    int     fd;

    if((fd = open("./test.file", O_RDWR | O_APPEND)) < 0) {
            perror("open file error");
            exit(0);
    }

    if(lseek(fd, -24, SEEK_END) < 0) {
        perror("lseek error");
    }

#if 0    
    char rbuf[128] = "";
    ssize_t n = read(fd, rbuf, 128);
    
    switch(n) {
        case -1:
            perror("read error!");
            break;
        case 24:
            printf("Read Success!\n");
            break;
        case 0:
            printf("Read Faild!\n");
            break;
    }
#else
    if(write(fd, buf, strlen(buf)) < 0) {
        perror("write error");
    } else {
        printf("Write Sucees!\n");
    }

#endif

    exit(0);
}

