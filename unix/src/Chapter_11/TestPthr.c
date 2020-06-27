/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *    Describe :                                                               *
 *          不加锁测试多线程修改同一个变量
 *
 *    Author   :  Xu-Jianhao                                                   *
 *                               Biu Biu Biu !!!                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "apue.h"
#include <pthread.h>

volatile int sum = 0;

void *thr_func(void *arg)
{
    int i = (int)arg;
    while(i != 0) {
        sum++;
        i--;
    }
    pthread_exit((void *)0);
}

int main(int argc, char *argv[])
{
    pthread_t   tid[10];
    int         i;
    int         err;

    if(argc < 2) {
        err_sys("Usage: TestPthr [times]");
    }


    for(i = 0; i < 10; i++) {
        err = pthread_create(&tid[i], NULL, thr_func, (void *)atoi(argv[1]));
        if(err != 0)
            err_exit(err, "Can't create with pthread %d\n", i+1);
        err = pthread_detach(tid[i]);
        if(err != 0)
            err_exit(err, "Can't detach with pthread %d\n", i+1);
    }

    sleep(10);
    printf("Done!\n");
    printf("sum = %d\n", sum);

    exit(0);
}

