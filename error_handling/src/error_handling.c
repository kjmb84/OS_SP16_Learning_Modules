#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "../include/error_handling.h"

int create_blank_records(Record_t **records, const size_t num_records) {
    if (records != NULL  || num_records < 1)
        return -1;
    else {
        *records = (Record_t*) malloc(sizeof(Record_t) * num_records);

        memset(*records,0,sizeof(Record_t) * num_records);
        return 0;
    }

}

int read_records(const char *input_filename, Record_t *records, const size_t num_records) {
    if (!input_filename || *input_filename == ' ' || !records || num_records < 1)
        return -1;
	int fd = open(input_filename, O_RDONLY);
	if (fd == -1)
        return -2;
    if (num_records > fd)
        return -3;

  ssize_t data_read = 0;
  for (size_t i = 0; i < num_records; ++i) {
		data_read = read(fd,&records[i], sizeof(Record_t));
		if (data_read == -1)
            return -3;
	}
	return 0;
}

int create_record(Record_t **new_record, const char* name, int age) {
    if (!*new_record || !name || *name == ' ' || age < 0)
        return -1;
	*new_record = (Record_t*) malloc(sizeof(Record_t));

	memcpy((*new_record)->name,name,sizeof(char) * strlen(name));
	(*new_record)->name[MAX_NAME_LEN - 1] = 0;
	(*new_record)->age = age;
	return 0;

}
