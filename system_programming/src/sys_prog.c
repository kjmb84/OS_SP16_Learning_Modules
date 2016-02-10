#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "../include/sys_prog.h"

// LOOK INTO OPEN, READ, WRITE, CLOSE, FSTAT/STAT, LSEEK
// GOOGLE FOR ENDIANESS HELP

bool bulk_read(const char *input_filename, void *dst, const size_t offset, const size_t dst_size) {
    if (!input_filename || !dst || dst_size < 1 || offset > dst_size)
        return false;
    int fildes = open(input_filename, O_RDONLY);//open so that it can only be read
    struct stat buf;//something for the status to be held in
    int status = fstat(fildes, &buf);//get status of file
    if (status == -1)
        return false;
    else {
        if (-1 == pread(fildes,dst,dst_size,offset)) {//check if read failed
            close(fildes);
            return false;
        }
        else {
            close(fildes);
            return true;
        }

    }
    return false;
}

bool bulk_write(const void *src, const char *output_filename, const size_t offset, const size_t src_size) {
    if (!output_filename || !src || src_size < 1)
        return false;
    int fildes = open(output_filename, O_WRONLY,O_CREAT,O_EXCL);//open so that a file is either opened or created
    struct stat buf;//holds status of file
    int status = fstat(fildes, &buf);//gets status of file
    if (status == -1)
        return false;
    else {
        if (-1 == pwrite(fildes,src,src_size,offset)) {//check if the write fails
            close(fildes);
            return false;
        }
        else {
            close(fildes);
            return true;
        }

    }
	return false;
}


bool file_stat(const char *query_filename, struct stat *metadata) {
    if (!query_filename)
        return false;
    if (metadata == NULL)
        return false;
    else {
        int fildes = open(query_filename,O_RDWR);//open as read or write and get status
        if (fildes == -1)
            return false;
        int status = fstat(fildes,metadata);//get status of file
        if (status == -1)//checm if failed or passed
            return false;
        return true;
    }
}

bool endianess_converter(uint32_t *src_data, uint32_t *dst_data, const size_t src_count) {
    if (!src_data || !dst_data|| src_count < 1)
        return false;
    else {
        for (size_t i = 0;i < src_count;i++) {
            dst_data[i] = be32toh(src_data[i]);//converts the endianness
        }
        return true;
    }
}
