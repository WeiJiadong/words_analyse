#ifndef WORD_ANALYSE_H_INCLUDED
#define WORD_ANALYSE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

/*状态码*/
#define OK     (0)
#define NG     (-1)

/*常量值*/
#define MAX_SIZE (40960)
#define FILE_LEN (256)
/*删除注释和空行*/
int deal_note(char *str);
/*获得文件内容*/
char *get_file(char *file_name);
int externs_head_file(char *str);


#endif/*WORD_ANALYSE_H_INCLUDED*/
