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
    else {
        char *dst_str = (char *) malloc(length);
        strncpy(dst_str, str, length);
        dst_str[length+1] = '\0';
        return dst_str;
/*
        memcpy(dst_str, str, sizeof(char) * length);
        dst_str[length] = '\0';
*/
        /*for (size_t i=0;i < length;i++) {
            //dst_str[i] = str[i];

        }*/
    }

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
    if (!str || !delims || str_length < 1 || !tokens || max_token_length < 1 || requested_tokens < 1)
        return 0;
    else {

        for (int i = 0;i < requested_tokens;i++)
            if (!tokens[i])
                return -1;
        /*
        int i=0;
        tokens[i++] = strtok(str, delims);
        while (!tokens)
            tokens[i++] = strtok(NULL, delims);
        return i;
    */
//need to add null terminator to end of strings in tokens
//Also need to find a way to get the last token from the string
        size_t toks = 0;
        size_t since_tok = 0;
        for (size_t i = 0;i < str_length;i++, ++since_tok) {
            if (str[i] == *delims) {
                strncpy(tokens[toks++], &str[i-since_tok], since_tok);
                since_tok = 0;
                printf("\n%s\n",tokens[toks-1]);
            }
        }
        return toks;
    }
}

bool string_to_int(const char *str, int *converted_value) {
    if (!str || !converted_value)
        return false;
    int len = strlen(str);
    if (len > 10)
        return false;
    for (int i = 0;i < len;i++) {
        if (str[i] != ' ') {
            printf("\n%d\n", *converted_value);
            *converted_value = *converted_value * 10 + (str[i] - '0');
        }
        else
            return true;
    }
	return true;
}
