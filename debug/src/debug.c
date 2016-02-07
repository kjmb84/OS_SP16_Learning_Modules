#include "../include/debug.h"

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// protected function, that only this .c can use
int comparator_func(const void *a, const void *b) {
    return (*(uint16_t *)a - *(uint16_t *)b);
}

bool terrible_sort(uint16_t *data_array, const size_t value_count) {
    if (!data_array || value_count < 1)
        return false;
    uint16_t *sorting_array =(uint16_t *) malloc(value_count * sizeof(uint16_t));

    qsort(data_array, value_count, sizeof(uint16_t), *comparator_func);

    bool sorted = true;
    for (int i = 0; i < value_count-1; i++) {
        sorted &= (data_array[i] <= data_array[i + 1]);
    }

    if (sorted) {
        memcpy(sorting_array, data_array, value_count);
    }
    return sorted;
}

