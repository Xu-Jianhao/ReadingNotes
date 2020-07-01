/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *    Describe :                                                               *
 *          实现getenv,此版本是不可重入的,如果两个线程同时调用这个函数,
 *          就会看到不一致的结果,因为所有调用getenv的线程返回的字符串都
 *          存储在同一个静态缓冲区.
 *
 *    Author   :  Xu-Jianhao                                                   *
 *                               Biu Biu Biu !!!                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "apue.h"
#include <limits.h>
#include <string.h>

#define MAXSTRINGSZ 4096

static char envbuf[MAXSTRINGSZ];
extern char **environ;

char *getenv(const char *name)
{
    int i,len;

    len = strlen(name);
    for(i = 0; environ[i] != NULL; i++) {
        if((strncmp(name, environ[i], len) == 0) && (environ[i][len] == '=')) {
            strncpy(envbuf, &environ[i][len+1], MAXSTRINGSZ-1);
            return(envbuf);
        }
    }
    return(NULL);
}

int main(void)
{
    printf("name is %s\n", getenv("name"));
    exit(0);
}

