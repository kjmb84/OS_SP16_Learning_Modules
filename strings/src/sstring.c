#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <ctype.h>


#include "../include/sstring.h"

bool string_valid(const char *str, const size_t length) {
    if (!str)
        return false;
    for (size_t i = 0;i < length;i++) {
        if (str[i] == '\0')//if string has an end
            return true;
    }
    return false;
}

char *string_duplicate(const char *str, const size_t length) {
    if (!str || length < 1)
        return NULL;
    else {
        char *dst_str = (char *) malloc(length);
        strncpy(dst_str, str, length);//copies source string into string
        dst_str[length+1] = '\0';//ends string
        return dst_str;
    }

	return NULL;

}

bool string_equal(const char *str_a, const char *str_b, const size_t length) {
    if (!str_a || !str_b || length < 1)
        return false;
    else {
        if (strcmp(str_a, str_b) != 0)//simple compare, if equal return true, else false
            return false;
        return true;
    }
}

int string_length(const char *str, const size_t length) {
    if (!str || length < 1)
        return -1;
    else {
        for (int i = 0;i < length;i++) {
            if (str[i] == '\0')//loops through, incrementing until end of string is found
                return i;//returns incremented i
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
        size_t toks = 0;//initializes amount of tokens found to 0
        size_t since_tok = 0;//initializes counts chars since the last token
        char nullingString[max_token_length];//string gets put here first to put a terminating character

        for (size_t i = 0;i < str_length;i++, ++since_tok) {
            if (str[i] == *delims || str[i] == '\0') {//if the string character matches the delimiter, move into block
                strncpy(nullingString,&str[i-since_tok],since_tok);//copy all characters since last token into string
                nullingString[since_tok] = '\0';//set a terminating character at end of string
                strcpy(tokens[toks++], nullingString);//copy the just terminated string into the tokens array
                since_tok = 0;//there was just a token, reset this
                i++;
            }
        }
        return toks;
    }
}

bool string_to_int(const char *str, int *converted_value) {//I finished this, and then I found out about string to long. It's ugly
    if (!str || !converted_value)
        return false;
    int len = strlen(str);//find length of string
    int array[10] = {2,1,4,7,4,8,3,6,4,7};//int can't be bigger than these numbers in these specific positions
    if (len > 10)//if it's larger than 9.99... billion it automatically fails because it's definitely bigger than above
        return false;
    for (int i = 0;i < len;i++) {
        if (!isspace(str[i])) {//check to make sure char is not a space
            if (str[i]- '0' <= array[i]) {//check to make sure value will be less than what's stored in array
                *converted_value = *converted_value * 10 + (str[i] - '0');//convert to int
            }
            else {
                *converted_value = 0;//reset value if invalid string
                return false;
            }
        }
        else
            return true;
    }
	return true;
}
