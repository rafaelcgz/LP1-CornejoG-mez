#include <stdio.h>

int main(void) {
    int v[8] = {10, 20, 30, 40, 50, 60, 70, 80};

    int *p = v;
    printf("*p = %d\n", *p);
    printf("*(p + 1) = %d\n", *(p + 1));
    printf("*(p + 7) = %d\n", *(p + 7));
    printf("p[3] = %d\n", p[3]);
    printf("3[p] = %d\n", 3[p]);
    printf("(p + 5) - p = %lld\n", (p + 5) - p);
    printf("sizeof(int) = %zu\n\n", sizeof(int));

    int suma = 0;
    printf("Recorrido forward: ");
    for (int *ptr = v; ptr < v + 8; ptr++) {
        printf("%d ", *ptr);
        suma += *ptr;
    }
    printf("\nSuma: %d\n\n", suma);

    printf("Recorrido reverse: ");
    for (int *ptr = &v[7]; ptr >= v; ptr--) {
        printf("%d ", *ptr);
    }
    printf("\n");

    return 0;
}