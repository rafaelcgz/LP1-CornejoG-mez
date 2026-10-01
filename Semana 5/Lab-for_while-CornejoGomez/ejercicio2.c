#include <stdio.h>

int main() {
    int max_pasos = 0;
    int mejor_n = 0;

    for (int i = 1; i <= 10000; i++) {
        int temp = i;
        int pasos = 0;

        while (temp != 1) {
            if (temp % 2 == 0) {
                temp = temp / 2;
            } else {
                temp = 3 * temp + 1;
            }
            pasos++;
        }

        if (pasos > max_pasos) {
            max_pasos = pasos;
            mejor_n = i;
        }
    }

    printf("Mayor semilla en [1, 10000]: n = %d, semilla = %d\n", mejor_n, max_pasos);

    return 0;
}