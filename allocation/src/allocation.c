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
        if (!ptr) //check to make sure pointer is currently set to null
            return (ptr = malloc(size));
        else {
            ptr = realloc(ptr, size); //if pointer is not null, increase space given to it
            return ptr;
        }
    }
	return NULL;
}

void deallocate_array(void** ptr)
{
    if (!ptr)
        return;
    else {
        free(*ptr);
        *ptr = NULL;
        return;
    }
	return;
}

char* read_line_to_buffer(char* filename)
{
    if (!filename)
        return filename;
    else {
        FILE *fp = fopen(filename, "r");
        fseek(fp,0L,SEEK_END); //For find ending of file
        int sz=ftell(fp);//Store size in variable
        rewind(fp);//set pointer back to beginning of file
        char *buffer = (char *) malloc(sz*sizeof(char));//create buffer for file to be read into
        fread(buffer, sizeof(char), sz, fp);
        buffer[sz] = '\0';//give buffer ending point
        fclose (fp);
        return buffer;
    }
	return NULL;
}
