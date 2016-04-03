#include <words_analyse.h>

/*头文件展开*/
int externs_head_file(char *str)
{
    int loop  = 0;
    int begin = 0;
    int index = 0;
    char *res = NULL;
    char path[FILE_LEN] = {0};
    char temp[FILE_LEN] = {0};

    if (NULL == str) {
        printf("文件名不能为空！");
        return NG;
    }/*end if*/

    strcpy(path, "/usr/include/");

    for (loop = 0; str[loop]; ++loop) {
        if ('#' == str[loop]) {
            if (!strncmp(str + loop + 1, "include", strlen("include"))) {
                for (begin = loop + strlen("include") + 1; str[begin]
                                          &&  str[begin] != '<'; ++begin);
                if ('<' == str[begin]) {
                    begin++;
                }/*end if*/
                for (index = 0; str[begin] && str[begin] != '>' && str[begin] != ' ';) {
                    temp[index++] = str[begin++];
                }/*end for*/
                strcat(path, temp);
                res = get_file(path);
                if (!res) {
                    perror("文件打开失败！");
                    return NG;
                }/*end if*/
                printf ("%s :\n %s\n",temp, res);
                memset(temp, 0x00, FILE_LEN);
                strcpy(path, "/usr/include/");
            }/*end if*/
        }/*end if*/
    }/*end for*/

    return OK;
}
