#include "../include/structures.h"

int compare_structs(sample_t* a, sample_t* b)
{
    if (a->a == b->a && a->b == b->b && a->c == b->c)
        return 1;
    return 0;
}

void print_alignments()
{
	printf("Alignment of int is %zu bytes\n",__alignof__(int));
	printf("Alignment of double is %zu bytes\n",__alignof__(double));
	printf("Alignment of float is %zu bytes\n",__alignof__(float));
	printf("Alignment of char is %zu bytes\n",__alignof__(char));
	printf("Alignment of long long is %zu bytes\n",__alignof__(long long));
	printf("Alignment of short is %zu bytes\n",__alignof__(short));
	printf("Alignment of structs are %zu bytes\n",__alignof__(fruit_t));
}

int sort_fruit(const fruit_t* a,int* apples,int* oranges, const size_t size)
{
	return 0;
}

// Purpose: Initializes an array of fruits with the specified number of apples and oranges
// Receives: fruit_t* a - pointer to an array of fruits
//						int apples - the number of apples
//						int oranges - the number of oranges
// Returns: -1 if there was an error, 0 otherwise.
int initialize_array(fruit_t* a, int apples, int oranges)
{
    if (a || apples < 0 || oranges < 0)
        return -1;
    a = (fruit_t *) malloc((apples + oranges)*sizeof(int));
    if (a)
        return 0;
    return -1;
}

int initialize_orange(orange_t* a)
{
    if (a)
        return -1;
    a = (orange_t *) malloc(sizeof(orange_t));
	if (a)
        return 0;
    return -1;
}

int initialize_apple(apple_t* a)
{
    if (a)
        return -1;
    a = (apple_t *) malloc(sizeof(apple_t));
	if (a)
        return 0;
    return -1;
}
