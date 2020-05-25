#include "apue.h"

/* Program :
 *          Print user's UID and GID 
 */

int main(void)
{
    printf("uid = %d, gid = %d\n", getuid(), getgid());
    exit(0);
}
