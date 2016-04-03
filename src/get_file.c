#include <words_analyse.h>

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
