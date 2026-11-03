#include <stdlib.h>
#include <stdio.h>
#include "tribulle.h"



int array_init(Array arr, int intialCapacity) {
    arr->size = 0;
    arr->capacity = intialCapacity;
    arr->elements = malloc(sizeof(int) * intialCapacity);

    return arr->elements != NULL;
}

void array_push(Array arr, int value) {
    arr->elements[arr->size++] = value;

    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;
        arr->elements = realloc(arr->elements, arr->capacity * sizeof(int));
    }
}

void array_free(Array arr) {
    free(arr->elements);
    arr->elements = NULL;
}

void array_print(const Array arr) {
    for (int i = 0; i < arr->size; i++)
    {
        printf("arr[%d] = %d\n", i, arr->elements[i]);
    }
}

void trier(Array arr) {
    int tmp;
    int sorted = 0;

    for (int i = arr->size - 1; i >= 1 ; i--)
    {
        sorted = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr->elements[j + 1] < arr->elements[j]) {
                tmp = arr->elements[j];
                arr->elements[j] = arr->elements[j + 1];   
                arr->elements[j + 1] = tmp;   
                sorted = 0;
            }
        }
        if (sorted) return;
    }
}

int test_sorted(const Array arr) {
    for (int i = 0; i < arr->size - 1; i++) {
        if (arr->elements[i] > arr->elements[i + 1]) return 0;
    }
    return 1;
} 
