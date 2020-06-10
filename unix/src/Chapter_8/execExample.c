/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *  Describe :                                                                 *
 *          exec function Example
 *
 *  Author   :  Xu-Jianhao                                                     *
 *                              Biu Biu Biu !!!                                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "apue.h"
#include <sys/wait.h>

char *env_init[] = {"USER=unknown", "PATH=/tmp", NULL};

int main(void)
{
    pid_t   pid;

    if((pid = fork()) < 0) {
        err_sys("fork error");
    } else if(pid == 0) {       /* specify pathname, specify environment */
        if(execle("/home/xjh/Space/git/ReadingNotes/unix/bin/echoarg", "echoarg", "myarg1",
                    "MYARG2", (char *)0, env_init) < 0)
            err_sys("execle error");
    }

    if(waitpid(pid, NULL, 0) < 0)
        err_sys("wait error");

    if((pid = fork()) < 0)
        err_sys("fork error");
    else if(pid == 0) {         /* specify filename, inherit environment */
        if(execlp("bin/echoarg", "echoarg", "only 1 arg", (char *)0) < 0)
            err_sys("execlp error");
    }

    exit(0);
}
