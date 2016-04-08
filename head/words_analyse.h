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
#define KEY_NUMS (32)
#define KEY_LENS (20)
#define HASH_LEN (26)

char key_words[KEY_NUMS][KEY_LENS];
char *hash_map[HASH_LEN];

/*删除注释和空行*/
int deal_note(char *str);
/*获得文件内容*/
char *get_file(char *file_name);
/*展开头文件*/
int externs_head_file(char *str);
/*初始化关键字表*/
int ident_init();
/*判断是否为关键字*/
int is_ident(char *str);

#endif/*WORD_ANALYSE_H_INCLUDED*/
