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
    if (!a || apples < 0 || oranges < 0 || size < 1)
        return -1;
    else {
        int i = 0;
        for (i = 0;i < size;i++,a++) {
            if (a->type == ORANGE){
                *oranges+=1;
            }
            if (a->type == APPLE) {
                *apples+=1;
            };
        }
        return i;
    }
    return -1;
}

int initialize_array(fruit_t* a, int apples, int oranges)
{
    if (!a || apples < 0 || oranges < 0)
        return -1;
    int i = 0;
    for (i = 0;i < apples;i++,a++) {
        a->type = APPLE;
    }
    for (i = 0;i < oranges;i++,a++) {
        a->type = ORANGE;
    }
    return 0;
}

int initialize_orange(orange_t* a)
{
    if (!a)
        return -1;
    if (a) {
        a->type = ORANGE;
        return 0;
    }
    return -1;
}

int initialize_apple(apple_t* a)
{
    if (!a)
        return -1;
    if (a) {
        a->type = APPLE;
        return 0;
    }
    return -1;
}
