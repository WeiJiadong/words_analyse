#include <words_analyse.h>
/*判断是否为关键字*/

int is_ident(char *str)
{
    int loop  = 0;

    if (!str) {
        perror("传入指针为空！");
        return NG;
    }/*end if*/
    printf("包含的关键字为：\n");
    for (loop = 0; str[loop]; ++loop) {
        if ('#' == str[loop]) {   /*跳过以#开始的部分*/
            while (str[loop] && str[loop++] != '\n');
        }/*end if*/
        if (str[loop] >= 'a' && str[loop] <= 'z' && hash_map[str[loop] - 'a']) {
            if (!strncmp(str + loop, hash_map[str[loop] - 'a'], strlen(hash_map[str[loop] - 'a']))) {
                printf("%s\n", hash_map[str[loop] - 'a']);
                loop += strlen(hash_map[str[loop] - 'a']);
            }/*end if*/
        }/*end if*/
    }/*end for*/

    return OK;
}
