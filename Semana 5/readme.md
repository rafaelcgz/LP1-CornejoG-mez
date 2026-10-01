----LABORATORIO(FUNCIONES)------
PREGUNTAS GUÍA (1.2) 
1. ¿Por qué n sigue siendo 10 en main?
Porque en C las funciones reciben parámetros por valor. La función modifica solo una copia local (x), dejando a n intacta en main.
2. ¿Cémo se resolvería sin usar punteros?
Cambiando la función para que retorne el nuevo valor (return x;) y reasignándolo en main (n = incrementar(n);).
3. Reescribir incrementar para que retorne el valor
modificado.

#include <stdio.h>
int incrementar(int x) {
    x = x + 1;
    printf("Dentro de incrementar: x = %d\n", x);
    return x;
}

int main(void) {
    int n = 10;
    n = incrementar(n); // Reasignamos el valor retornado a n
    printf("Despues de llamar: n = %d\n", n); 

    return 0;
}
ACTIVIDADES(1.3)
1. Predecir la salida de cada uno.
Salida del Programa A:
local contador = 1
local contador = 1
local contador = 1
global contador = 0
Salida del Programa B:
global contador = 3

2. Compilar y verificar. ¿Sorpresa?

Al compilar y ejecutar ambos programas, la sorpresa del Programa A es que la variable global nunca cambia y se queda en 0, porque la variable local hizo un shadowing (sombramiento) y ocultó a la global en su propio ámbito. En cuanto al Programa B, la sorpresa radica en lo fácil que es romper la encapsulación: la función modifica directamente la variable global sin recibir ningún parámetro, lo que a simple vista parece práctico pero destruye la modularidad del código.   

3. Refactorizar para eliminar la variable global: pasar el
contador por parámetro y retornar el nuevo valor:

#include <stdio.h>
int incrementar(int contador) {
    return contador + 1;
}

int main(void) {
    int contador = 0;

    contador = incrementar(contador);
    contador = incrementar(contador);
    contador = incrementar(contador);

    printf("global contador = %d\n", contador);

    return 0;
}

4. Discusión: ¿Por qué las variables globales son una mala
práctica en Ingeniería de Software? Mencionar al menos
tres razones (acoplamiento, dificultad de testeo,
condiciones de carrera en concurrencia).
    -Acoplamiento fuerte: Generan dependencias ocultas entre distintas partes del código
    -Dificultad de testeo: Complican las pruebas unitarias al depender de un estado compartido.
    Condiciones de carrera: Provocan errores impredecibles en entornos concurrentes.
