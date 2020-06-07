/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *  Describe :                                                                 *
 *          setjmp and longjmp example.
 *
 *  Author   :  Xu-Jianhao                                                     *
 *                              Biu Biu Biu !!!                                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "apue.h"
#include <setjmp.h>

#define TOK_ADD 5

jmp_buf jmpbuffer;
int i = 1;

void do_line(char *);
void cmd_add(void);
int  get_token(void);

int main(void)
{
    char line[MAXLINE];

    if(setjmp(jmpbuffer) != 0)          /* setjmp 设置程序跳转返回点,参数jmpbuffer设置为全局变量 */
        printf("longjmp return i = %d\n", i);

    while(fgets(line, MAXLINE, stdin) != NULL)
        do_line(line);

    exit(0);
}

char *tok_ptr;      /* global pointer for get_token() */

void do_line(char *ptr)     /* process one line of input */
{
    int cmd;

    tok_ptr = ptr;
    while((cmd = get_token()) > 0) {
        switch(cmd) {       /* one case for each command */
            case TOK_ADD:
                cmd_add();
                break;
            case 8:
                cmd_add();
                break;
            case 15:
                cmd_add();
                break;
        }
    }
}

void cmd_add(void)
{
    int token;

    token = get_token();
    if(token > 12)
        longjmp(jmpbuffer, 1);      /* an error has occurred, 我们希望直接跳转回main */
    /* rest of processing for this command */
    printf("-----%s----\n", __FUNCTION__);
}

int get_token(void)
{
    /* fetch next token from line pointed to by tok_ptr */
    i++;
    return i;
}
