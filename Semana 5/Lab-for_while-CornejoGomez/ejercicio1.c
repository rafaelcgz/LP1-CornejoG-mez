#include <stdio.h>

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

    int num_ingresado = n;

    printf("\nNumero ingresado: %d\n", num_ingresado);
    printf("Secuencia de reduccion: ");

    while (n >= 10) {
        printf("%d -> ", n);

        int suma = 0;
        int temp = n;

        while (temp > 0) {
            suma += temp % 10;
            temp /= 10;
        }

        n = suma;
    }

    printf("%d\n", n);
    printf("Ultimo digito: %d\n", n);

    return 0;
}