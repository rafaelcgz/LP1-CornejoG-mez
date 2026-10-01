#include <stdio.h>
#include <math.h>

int main() {
    double tolerancia = 1e-6;
    double suma = 0.0;
    long long iteraciones = 0;
    double termino = 1.0;
    int signo = 1;
    long long i = 1;

    while (1) {
        termino = 1.0 / (double)i;
        if (termino < tolerancia) {
            break;
        }

        if (signo == 1) {
            suma += termino;
        } else {
            suma -= termino;
        }

        signo = -signo;
        iteraciones++;
        i++;
    }

    double ln2_esperado = 0.693147;
    double error_absoluto = fabs(suma - ln2_esperado);

    printf("Tolerancia: 1e-6\n");
    printf("Iteraciones: %lld (aprox.)\n", iteraciones);
    printf("Suma calculada : %.6f\n", suma);
    printf("ln(2) esperado : %.6f\n", ln2_esperado);
    printf("Error absoluto : %.6f\n", error_absoluto);

    return 0;
}