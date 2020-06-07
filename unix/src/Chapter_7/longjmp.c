/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *  Describe :                                                                 *
 *          测试longjmp函数对各类变量的影响
 *
 *  Author   :  Xu-Jianhao                                                     *
 *                              Biu Biu Biu !!!                                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "apue.h"
#include <setjmp.h>

static void f1(int, int, int, int);
static void f2(void);

static jmp_buf   jmpbuffer;
static int      globval;

int main(void)
{
    int             autoval;    /* 自动变量 */
    register int    regival;    /* 寄存器变量 */
    volatile int    volaval;    /* 禁止编译器优化变量 */
    static int      statval;    /* 静态变量 */

    globval = 1;
    autoval = 2;
    regival = 3;
    volaval = 4;
    statval = 5;

    if(setjmp(jmpbuffer) != 0) {
        printf("after longjmp:\n");
        printf("globval = %d\nautoval = %d\nregival = %d\nvolaval = %d\nstatval = %d\n", globval, autoval, regival, volaval, statval);
        exit(1);
    }
    /*
     * Change variables after setjmp, but before longjmp.
     */
    globval = 95;
    autoval = 96;
    regival = 97;
    volaval = 98;
    statval = 99;

    f1(autoval, regival, volaval, statval); /* never returns */
    exit(0);
}

static void f1(int i, int j, int k, int l)
{
    printf("in f1():--------------\n");
    printf("globval = %d\nautoval = %d\nregival = %d\nvolaval = %d\nstatval = %d\n", globval, i, j, k, l);
    f2();
}

static void f2(void)
{
    longjmp(jmpbuffer, 1);
}
