#include <words_analyse.h>

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
