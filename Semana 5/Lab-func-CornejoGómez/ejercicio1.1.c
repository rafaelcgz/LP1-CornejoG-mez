#include <stdio.h>

int suma_digitos(int n) {
    int suma = 0;
    while (n > 0) {
        suma += n % 10;
        n /= 10;
    }
    return suma;
}

int raiz_digital(int n) {
    while (n >= 10) {
        n = suma_digitos(n);
    }
    return n;
}

void imprimir_traza(int n) {
    while (n >= 10) {
        printf("%d -> ", n);
        n = suma_digitos(n);
    }
    printf("%d\n", n);
}

int main() {
    int n;

    do {
        printf("Ingrese un numero entero positivo: ");
        if (scanf("%d", &n) != 1) {
            printf("Error: Debe ingresar un numero entero.\n");
            while (getchar() != '\n');
            n = 0;
        } else if (n <= 0) {
            printf("El numero debe ser mayor a cero.\n");
        }
    } while (n <= 0);

    printf("\nNumero ingresado: %d\n", n);
    printf("Secuencia de reduccion: ");
    imprimir_traza(n);
    printf("Ultimo digito: %d\n", raiz_digital(n));

    return 0;
}