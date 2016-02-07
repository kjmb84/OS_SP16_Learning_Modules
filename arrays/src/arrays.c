#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "../include/arrays.h"

// LOOK INTO MEMCPY, MEMCMP, FREAD, and FWRITE

bool array_copy(const void *src, void *dst, const size_t elem_size, const size_t elem_count) {
	if (elem_size == 0 || elem_count == 0 || !src || !dst) //check to make sure input parameters are valid
		return false; //if fails, return false
	else {
        if (memcpy(dst, src, elem_count*elem_size))
            return true;
    }
    return false; //function failure
}

bool array_is_equal(const void *data_one, void *data_two, const size_t elem_size, const size_t elem_count) {
    if (!data_one || !data_two || elem_count == 0 || elem_size == 0)
        return false;
    else {
        if (memcmp(data_one, data_two, elem_count*elem_size) == 0)
            return true;
    }
	return false;
}

ssize_t array_locate(const void *data, const void *target, const size_t elem_size, const size_t elem_count) {
    if (!data || !target || elem_count == 0 || elem_size == 0)
        return -1;
    else {
        const char* d_ptr = (const char*) data;

        for (size_t i = 0;i < elem_count; ++i, d_ptr += elem_size) {
            if (memcmp(d_ptr, target, elem_size) == 0) {
                return i;
            }
        }
    }
    return -1;
}

bool array_serialize(const void *src_data, const char *dst_file, const size_t elem_size, const size_t elem_count) {
    if (!src_data || !dst_file || isspace(*dst_file) != 0 || elem_count == 0 || elem_size == 0)
        return false;
    else {
        FILE * dst_fp;
        dst_fp = fopen(dst_file, "w");
        if (dst_fp == NULL)
            return false;
        if (elem_count == fwrite(src_data, elem_size, elem_count, dst_fp))
            fclose(dst_fp);
            return true;
    }
    return false;
}

bool array_deserialize(const char *src_file, void *dst_data, const size_t elem_size, const size_t elem_count) {
    if (!src_file || !dst_data || elem_count == 0 || elem_size == 0)
        return false;
    else {
        FILE * src_fp;
        src_fp = fopen(src_file, "r");
        if (src_fp == NULL)
            return false;
        if (elem_count == fread(dst_data, elem_size, elem_count, src_fp))
            return true;
    }
	return false;
}
