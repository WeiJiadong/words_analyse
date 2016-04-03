#include <stdio.h>
#include <stdlib.h>
#include <words_analyse.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

/*删除注释*/
int deal_note(char *str)
{
    int loop  = 0;
    int begin = 0;
    int end   = 0;

    if (NULL == str) {    /*空的文件*/
        return OK;
    }/*end if*/

    for (loop = 0; str[loop]; ++loop) {
        if ('/' == str[loop]) {           /*可能为注释*/
            if ('/' == str[loop + 1]) {   /*为单行注释*/
                /*找注释的范围*/
                for (begin = loop; str[begin] && '\n' != str[begin]; ++begin);
                if ('\n' == str[begin]) {
                    ++begin;
                }/*end if*/
                for (end = begin, begin = loop; str[begin++] = str[end++];);
            }else {
                if ('*' == str[loop + 1]){ /*可能为多行注释*/
                    for (begin = loop + 2; str[begin] && str[begin + 1] &&
                                 ('*' != str[begin] || '/' != str[begin + 1]); ++begin);
                    if (!str[begin] || !str[begin]) {
                        return NG;
                    }/*end if*/
                    if ('\n' == str[begin + 2]) {
                        begin++;
                    }/*end if*/
                    for (end = begin + 2, begin = loop;str[begin++] = str[end++];);
                }/*end if*/
            }/*end else*/
        }/*end if*/

    }/*end for*/

    return OK;
}

/*获得文件内容*/
char *get_file(char *file_name)
{
    int   fd = -1;
    char *res = NULL;

    if (!file_name) {
        perror("文件名不能为空！");
        return res;
    }/*end if*/

    fd = open(file_name, O_RDONLY);
    if (fd < 0) {
        perror("文件打开失败！");
        return res;
    }/*end if*/

    res = (char *)malloc(MAX_SIZE);
    if (!res) {
        perror("内存不足！");
        return res;
    }/*end if*/

    memset(res, 0x0, MAX_SIZE);

    if (read(fd, res, MAX_SIZE) < 0) {
        perror("读取文件失败!");
        return res;
    }/*end if*/

    return res;
}

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
