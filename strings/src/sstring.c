#include <string.h>
#include <errno.h>
#include <stdio.h>


#include "../include/sstring.h"

bool string_valid(const char *str, const size_t length) {
    if (!str)
        return false;
    for (size_t i = 0;i < length;i++) {
        if (str[i] == '\0')
            return true;
    }
    return false;
}

char *string_duplicate(const char *str, const size_t length) {
    //char *dst_str[length];
    if (!str || length < 1)
        return NULL;
    //char *dst_str[length];
    else
        return NULL;
        /*char dst_str[length];
        strncpy(dst_str, str, length);
        dst_str[length+1] = '\0';
        return dst_str;

        memcpy(dst_str, str, sizeof(char) * length);
        dst_str += '\0';*/
        /*for (size_t i=0;i < length;i++) {
            //dst_str[i] = str[i];

        }*/


	return NULL;

}

bool string_equal(const char *str_a, const char *str_b, const size_t length) {
    if (!str_a || !str_b || length < 1)
        return false;
    else {
        if (strcmp(str_a, str_b) != 0)
            return false;
        return true;
    }
}

int string_length(const char *str, const size_t length) {
    if (!str || length < 1)
        return -1;
    else {
        for (int i = 0;i < length;i++) {
            if (str[i] == '\0')
                return i;
        }
    }
    return -1;
}

int string_tokenize(const char *str, const char *delims, const size_t str_length,char **tokens, const size_t max_token_length, const size_t requested_tokens) {

	return 0;
}

bool string_to_int(const char *str, int *converted_value) {

	return true;
}
