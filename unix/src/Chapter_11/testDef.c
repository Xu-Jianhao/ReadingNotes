/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *    Describe :                                                               *
 *          测试_POSIX_THREADS宏
 *
 *    Author   :  Xu-Jianhao                                                   *
 *                               Biu Biu Biu !!!                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "apue.h"

int main(void)
{

#ifdef _POSIX_THREADS
    printf("YES!!\n");
#else
    printf("NO!!!\n");
#endif

    exit(0);
}

