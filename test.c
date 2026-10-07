#include "tribulle.h"

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

    int test_result = test_sorted(&arr);

    array_free(&arr);
    
    if (test_result) {
        printf("\x1B[32mLe test est validé\x1B[0m\n");
        
        return 0;
    } 
    
    printf("\x1B[31mLe test à échoué :/\x1B[0m\n");
    return 1;
}
