/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *  Describe :                                                                 *
 *          getpwnam 实现
 *
 *  Author   :  Xu-Jianhao                                                     *
 *                              Biu Biu Biu !!!                                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <pwd.h>
#include <stddef.h>
#include <string.h>

struct passwd *getpwnam(const char *name)
{
    struct passwd *ptr;

    setpwent();
    while((ptr = getpwent()) != NULL)
        if(strcmp(name, ptr->pw_name) == 0)
            break;      /* found a match */

    endpwent();
    return(ptr);    /* ptr is NULL if no match found */

}

int main(void)
{

    exit(0);
}

