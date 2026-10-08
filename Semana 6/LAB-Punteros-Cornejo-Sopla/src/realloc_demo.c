#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t cap = 2;
    size_t n = 0;
    int realloc_count = 0;

    int *v = (int *)calloc(cap, sizeof(int));
    if (v == NULL) {
        fprintf(stderr, "Error al reservar memoria inicial\n");
        return 1;
    }

    printf("Ingrese enteros (termine con -1):\n");

    int num;
    while (scanf("%d", &num) == 1 && num != -1) {
        if (n == cap) {
            size_t nueva_cap = cap * 2;
            
        
            int *tmp = (int *)realloc(v, nueva_cap * sizeof(int));
            if (tmp == NULL) {
                fprintf(stderr, "realloc fallo\n");
                free(v);
                return 1;
            }
            v = tmp; 
            cap = nueva_cap;
            realloc_count++;
        }

        v[n] = num;
        n++;
    }

    printf("\nElementos: %zu\n", n);
    printf("Capacidad final: %zu\n", cap);
    printf("Realloc llamados: %d\n", realloc_count);
    printf("Contenido: ");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    free(v);
    v = NULL;

    return 0;
}