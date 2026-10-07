#include <stdlib.h>
#include <stdio.h>

typedef struct array
{
    int capacity;
    int size;
    int* elements;
}* Array;


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

int main(void) {
    struct array arr;

    array_init(&arr, 16);

    for (int i = 0; i < 256; i++)
    {
        array_push(&arr, rand());
    }
    
    array_print(&arr);
    trier(&arr);
    array_print(&arr);

    arr.elements[1] = -456789; // Test erreur
    
    int test_result = test_sorted(&arr);

    array_free(&arr);
    
    if (test_result) {
        printf("\x1B[32mLe test est validé\x1B[0m\n");
        
        return 0;
    } 
    
    printf("\x1B[31mLe test à échoué :/\x1B[0m\n");
    return 1;
}
