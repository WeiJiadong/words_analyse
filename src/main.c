#include <words_analyse.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *file_str  = NULL;
    char *file_name = "test.c";
    int   res       = NG;

    file_str = get_file(file_name);
    if (!file_str) {
        return NG;
    }/*end if*/

    res = externs_head_file(file_str);
    if (NG == res) {
        perror("头文件展开失败！");
        return NG;
    }/*end if*/

    res = deal_note(file_str);
    if (NG == res) {
        perror("删除注释失败！");
        return NG;
    }/*end if*/

    printf("%s\n", file_str);

    res = ident_init();
    if (NG == res) {
        perror("初始化失败！");
        return NG;
    }/*end if*/

    res = is_ident(file_str);
    if (NG == res) {
        perror("关键字标示失败！");
        return NG;
    }/*end if*/

    return OK;
}
