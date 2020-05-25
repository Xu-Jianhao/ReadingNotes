#include "apue.h"
#include <errno.h>

int main(int argc, char *argv[])
{
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));      /* 输出EACCES错误 */
    
    errno = ENOENT;
    perror(argv[0]);

    exit(0);
}
