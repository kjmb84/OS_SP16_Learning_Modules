#include "../include/bitmap.h"

// data is an array of uint8_t and needs to be allocated in bitmap_create
//      and used in the remaining bitmap functions. You will use data for any bit operations and bit logic
// bit_count the number of requested bits, set in bitmap_create from n_bits
// byte_count the total number of bytes the data contains, set in bitmap_create
struct bitmap {
	uint8_t *data;
	size_t bit_count, byte_count;
};

bitmap_t *bitmap_create(size_t n_bits) {
    if (n_bits < 1 || n_bits > 65535)
        return NULL;
    bitmap_t *new_bitmap;
    new_bitmap = (bitmap_t *) malloc(sizeof(bitmap_t));
    if (n_bits%8 != 0)
        new_bitmap->byte_count = ((n_bits/8)+1);//set amount of bytes
    else
        new_bitmap->byte_count = (n_bits/8);

    new_bitmap->bit_count = n_bits;
    //new_bitmap->data = (uint8_t *) malloc(new_bitmap->byte_count); //set amount of memory given to data of bitmap
    new_bitmap->data = (uint8_t *) calloc(new_bitmap->byte_count, sizeof(uint8_t));
    //new_bitmap->data = 0;
    //new_bitmap->data[new_bitmap->byte_count] = {0};
    return new_bitmap;
}

bool bitmap_set(bitmap_t *const bitmap, const size_t bit) {
    //if (!bitmap || (bit != 1 && bit != 0))
    if (bit == 0) {
        bitmap->data[0] |= 1;
        return true;
    }
        /*
        int i = bit/8;
        int pos = bit%8;
        uint8_t flag = 1;
        flag = flag << pos;
        bitmap->data[i] = bitmap->data[i] | flag;

        return true;
    */
    if (!bitmap || bit < 1 || ceil(bit/8.0) > bitmap->byte_count)
        return false;
    else {
        bitmap->data[bit/8] |= 1 << (bit%8);
        return true;
    }

    /*
        //bitmap->data[bit/8] |= 1 << (bit%8);
        uint8_t i = bit/8;
        uint8_t pos = bit%8;
        uint8_t flag = 1;
        flag = flag << pos;
        bitmap->data[i] = (bitmap->data[i] | flag);
        return true;
    }*/
    return false;

    /*if (!bitmap || bitmap->bit_count < 1 || bitmap->byte_count < 1 || !bitmap->data || bit > 65535 || bit < 1)
        return false;

    if (!bitmap || bit > 65535)
        return false;
    else {
        bitmap->data[bit/8] |= (1 << (bit%8));
        return true;
    }*/
}

bool bitmap_reset(bitmap_t *const bitmap, const size_t bit) {
    if (!bitmap || bit > bitmap->bit_count)
        return false;
    else {
        bitmap->data[bit/8] &= ~(1 << (bit%8));
        return true;
    }
}

bool bitmap_test(const bitmap_t *const bitmap, const size_t bit) {
    if (!bitmap || bit > bitmap->bit_count)
        return false;
    else {
        uint8_t test = 1 << (bit%8);
        uint8_t test_cmp = test;
        test &= bitmap->data[bit/8];
        if (test != test_cmp)
            return false;
        else
            return true;
    }
}

size_t bitmap_ffs(const bitmap_t *const bitmap) {
    if (!bitmap)
        return SIZE_MAX;
    else
        for (size_t i = 0;i < bitmap->byte_count;i++) {

        }
        return 0;
}

size_t bitmap_ffz(const bitmap_t *const bitmap) {

	return 0;
}

bool bitmap_destroy(bitmap_t *bitmap) {
    if (!bitmap)
        return false;
    free(bitmap);
    if (bitmap)
        return true;
	return false;
}
