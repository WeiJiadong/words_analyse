#include <words_analyse.h>
int ident_init()
{
    int  index = 0;

    memset(key_words, 0x00, KEY_LENS * KEY_NUMS);
    memset(hash_map, 0x00, HASH_LEN);

    strcpy(key_words[0], "double");
    strcpy(key_words[1], "if");
    strcpy(key_words[2], "while");
    strcpy(key_words[3], "return");

    for (index = 0; index < KEY_NUMS; ++index) {
        if (key_words[index][0]) {
            hash_map[key_words[index][0] - 'a'] = key_words[index];
        }/*end if*/
    }/*end if*/

    return OK;
}
