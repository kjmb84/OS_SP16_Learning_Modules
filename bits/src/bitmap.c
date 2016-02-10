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
    if (n_bits%8 != 0)//check if amount of bits can be fit evenly into respective bytes
        new_bitmap->byte_count = ((n_bits/8)+1);//set amount of bytes if there are some left over
    else
        new_bitmap->byte_count = (n_bits/8);//set amount of bytes if none left over

    new_bitmap->bit_count = n_bits;
    new_bitmap->data = (uint8_t *) calloc(new_bitmap->byte_count, sizeof(uint8_t));//0 out allocated data space to prevent future conflicts
    return new_bitmap;
}

bool bitmap_set(bitmap_t *const bitmap, const size_t bit) {
    if (bit == 0) {
        bitmap->data[0] |= 1;//only used if it is the first bit to be set
        return true;
    }
    if (!bitmap || bit < 1 || ceil(bit/8.0) > bitmap->byte_count)
        return false;
    else {
        bitmap->data[bit/8] |= 1 << (bit%8);//move bit and set the bit in the byte from data
        return true;
    }
    return false;
}

bool bitmap_reset(bitmap_t *const bitmap, const size_t bit) {
   if (bit == 0) {
        bitmap->data[0] &= ~1;//only used if bit is the first to be reset
        return true;
    }
    if (!bitmap || bit > bitmap->bit_count)
        return false;
    else {
        bitmap->data[bit/8] &= ~(1 << (bit%8));//move bit and then reset that bit equivalent in the data byte
        return true;
    }
}

bool bitmap_test(const bitmap_t *const bitmap, const size_t bit) {
    if (!bitmap || bit > bitmap->bit_count)
        return false;
    else {
        uint8_t test = 1 << (bit%8);//set up bit to be tested
        uint8_t test_cmp = test;//set up bit to be compared to the original
        test &= bitmap->data[bit/8];
        if (test != test_cmp)//if the bit was changed the test fails
            return false;
        else
            return true;
    }
}

size_t bitmap_ffs(const bitmap_t *const bitmap) {
    if (!bitmap)
        return SIZE_MAX;
    else {
        uint8_t hanging_bits = bitmap->bit_count % 8;//check if there are bits that will be protruding into the next byte
        uint8_t bit_limit = 8;//this can be changed, that way the last byte will not be looped all the way through
        for (size_t i = 0;i < bitmap->byte_count;i++) {
            if (bitmap->data[i] != 0) {
                for (size_t j = 0;j < bit_limit;j++) {
                    uint8_t test = 1 << (j%8);
                    uint8_t test_cmp = test;
                    test &= bitmap->data[i];
                    if (test == test_cmp)//if the test is unchanged, a set bit was found
                        return (i*8 + j);//position of the byte * 8 plus the position of the bit
                }
            if (bitmap->byte_count == i)//if the last byte is reached, change limit so that extraneous bits aren't checked
                bit_limit = hanging_bits;
            }
        }
    }
    return SIZE_MAX;
}

size_t bitmap_ffz(const bitmap_t *const bitmap) {
    if (!bitmap)
        return SIZE_MAX;
    else {
        uint8_t hanging_bits = bitmap->bit_count % 8;
        uint8_t bit_limit = 8;
        for (size_t i = 0;i < bitmap->byte_count;i++) {
            if (bitmap->data[i] != 255) //if all bits are set then skip
                for (size_t j = 0;j < bit_limit;j++) { //bit_limit changes if the bit only proceeds partly into the byte being read.
                    uint8_t test = 1 << (j%8);
                    uint8_t test_cmp = test;
                    test &= bitmap->data[i];

                    if (test != test_cmp && ((i*8 + j) < bitmap->bit_count))
                        return (i*8 + j);
                }
            if (bitmap->byte_count == i)
                bit_limit = hanging_bits;
        }
    }
	return SIZE_MAX;
}

bool bitmap_destroy(bitmap_t *bitmap) {
    if (!bitmap)
        return false;
    free(bitmap);
    if (bitmap)
        return true;
	return false;
}
