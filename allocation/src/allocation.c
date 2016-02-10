#include "../include/allocation.h"

void* allocate_array(size_t member_size, size_t nmember,bool clear)
{
    if (member_size < 1 || nmember < 1)
        return NULL;
    if (clear) {
        size_t *array = (size_t *) calloc(nmember,member_size);
        return array;
    }
    else{
        size_t *array = (size_t *) malloc(nmember*member_size);
        return array;
    }
	return NULL;
}

void* reallocate_array(void* ptr, size_t size)
{
    if (size < 1)
        return NULL;
    else {
        if (!ptr)
            return (ptr = malloc(size));
        else {
            ptr = realloc(ptr, size);
            return ptr;
        }
    }
	return NULL;
}

void deallocate_array(void** ptr)
{
<<<<<<< HEAD
    if (!ptr)
        return;
    else {
        free(*ptr);
        *ptr = NULL;
        return;
    }
=======
	return;
>>>>>>> 49ecd14175656a948e92a1be49cc978b5871b7a4
}

char* read_line_to_buffer(char* filename)
{
    if (!filename)
        return filename;
    else {
        FILE *fp = fopen(filename, "r");
        fseek(fp,0L,SEEK_END);
        int sz=ftell(fp);
        printf("%d\n",sz);
        //fseek(fp,0L,SEEK_SET);
        rewind(fp);
        char *buffer = (char *) malloc(sz*sizeof(char));
        fread(buffer, sizeof(char), sz, fp);
        buffer[sz] = '\0';
        printf("\n%s\n\n", buffer);
        fclose (fp);
        return buffer;
    }
	return NULL;
}
