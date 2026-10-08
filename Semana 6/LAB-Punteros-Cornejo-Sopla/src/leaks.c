#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Fuga 1 corregida
    int *a = (int *)malloc(10 * sizeof(int));
    if (a != NULL) {
        free(a);
        a = NULL;
    }

    // Fuga 2 corregida
    int *b = (int *)calloc(5, sizeof(int));
    free(b);
    b = (int *)calloc(8, sizeof(int));
    if (b != NULL) {
        free(b);
        b = NULL;
    }

    // Error 3 (double free) corregido
    int *c = (int *)malloc(3 * sizeof(int));
    if (c != NULL) {
        free(c);
        c = NULL;
    }

    return 0;
}