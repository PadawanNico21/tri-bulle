#ifndef _H_TRIBULLE
#define _H_TRIBULLE 1

#include <stdio.h>
#include <stdlib.h>

typedef struct array
{
    int capacity;
    int size;
    int* elements;
}* Array;

int array_init(Array arr, int intialCapacity);
void array_push(Array arr, int value);
void array_free(Array arr);
void array_print(const Array arr);
void trier(Array arr);
int test_sorted(const Array arr);

#endif
