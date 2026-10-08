#include <stdio.h>

int main(void) {
    char *s = "Hola, mundo";

    printf("Cadena s: ");
    char *ptr = s;
    while (*ptr != '\0') {
        putchar(*ptr);
        ptr++;
    }
    putchar('\n');

    int longitud = 0;
    ptr = s;
    while (*ptr != '\0') {
        longitud++;
        ptr++;
    }
    printf("Longitud calculada: %d\n\n", longitud);
    char s2[] = "Hola, mundo";
    printf("s2 inicial: %s\n", s2);
    
    s2[0] = 'h';
    printf("s2 modificado: %s\n", s2);

    return 0;
}