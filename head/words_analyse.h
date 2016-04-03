#ifndef WORD_ANALYSE_H_INCLUDED
#define WORD_ANALYSE_H_INCLUDED

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



#endif/*WORD_ANALYSE_H_INCLUDED*/
