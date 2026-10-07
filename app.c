#include "tribulle.h"

int main(int argc, char **argv) {
    struct array arr;

    array_init(&arr, argc - 1);

    for (int i = 1; i < argc; i++)
    {
        array_push(&arr, atoi(argv[i]));
    }

    printf("Tableau entrée:\n");
    array_print(&arr);
    trier(&arr);
    printf("Tableau trié:\n");
    array_print(&arr);

    array_free(&arr);
}