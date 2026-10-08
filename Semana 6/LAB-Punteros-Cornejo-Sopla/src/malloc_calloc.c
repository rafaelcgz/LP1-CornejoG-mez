#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 10;

    int *p_malloc = (int *)malloc(n * sizeof(int));
    int *p_calloc = (int *)calloc(n, sizeof(int));

    if (p_malloc == NULL || p_calloc == NULL) {
        printf("Error al reservar memoria\n");
        free(p_malloc);
        free(p_calloc);
        return 1;
    }

    printf("malloc(10) antes de inicializar: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", p_malloc[i]);
    }
    printf("\n");

    printf("calloc(10) antes de inicializar: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", p_calloc[i]);
    }
    printf("\n\n");

    for (int i = 0; i < n; i++) {
        p_malloc[i] = i * i;
        p_calloc[i] = i * i;
    }

    printf("Tras llenar con cuadrados:\n");
    printf("malloc: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", p_malloc[i]);
    }
    printf("\n");

    printf("calloc: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", p_calloc[i]);
    }
    printf("\n\n");

    void *p_zero = malloc(0);
    printf("Prueba malloc(0): %p\n", p_zero);
    free(p_zero);

    free(p_malloc);
    free(p_calloc);
    p_malloc = NULL;
    p_calloc = NULL;

    return 0;
}