Laboratorio: Arreglos, Punteros y Gestión de Cadena de Carácteres 
Integrantes:
Cornejo Gómez Giovanni Rafael - Código:20250159A
Sopla Durand Jair Alexis - Código:20251125C

Bloque 2 — Punteros Básicos y Aritmética de Punteros

2.1 Declaración, desreferencia y dirección
 Respuestas:
 a) ¿Por qué printf("%p", p) requiere el cast (void *)? (Es por portabilidad y por las reglas de variadic functions.)

- Se usa (void *) porque el formato %p en printf exige recibir un puntero genérico. El cast evita advertencias del compilador y asegura que la dirección de memoria se imprima correctamente según el sistema.

b) ¿Qué diferencia hay entre int *p e int* p? ¿Y entre int *p, q y int *p, *q?

- Entre int *p e int* p no hay ninguna diferencia funcional; ambos declaran a p como puntero a entero y solo cambia el estilo de escritura.
- En int *p, q, solo p es un puntero a entero, mientras que q es una variable entera normal. En cambio, en int *p, *q, ambas variables son punteros a entero.

2.2 Aritmética de punteros sobre arreglos
Respuestas:

a) Concepto clave: p + 5 no suma 5 bytes, suma 5 * sizeof(int) bytes. Verifíquenlo imprimiendo (char *)p y (char *)(p+5) y calculando la diferencia en bytes con (char *)(p+5) - (char *)p.
   
- La expresión p + 5 no avanza 5 bytes en memoria, sino 5 posiciones de tipo entero, lo cual equivale a 20 bytes en total. Al realizar la conversión a (char *), la resta da como resultado 20 porque la unidad de salto se evalúa directamente en bytes.

b) ¿Por qué p[i] es exactamente *(p + i)? ¿Qué dice el estándar C al respecto?

- Es una equivalencia sintáctica del estándar de C definida exactamente como *(p + i).

c) ¿Por qué 3[p] compila? Explicar la conmutatividad de + y la definición de [].

- Es válida porque la suma de punteros es conmutativa; 3[p] se traduce como *(3 + p), que equivale a *(p + 3).

d) Trampa: ¿qué pasa con p + 8 (uno más allá del último elemento)? ¿Es válido
crearlo? ¿Se puede desreferenciar?

- Apuntar a p + 8 es legal solo para comparar el final de un bucle, pero desreferenciarlo (*(p + 8)) causa un error de acceso a memoria inválida.

2.3 Punteros a char y cadenas literales 
Respuestas:
a) ¿Cuál es la diferencia entre char *s = "..." y char s[] = "..." en términos de memoria?

- La declaración char *s apunta a una cadena literal guardada en memoria de solo lectura, mientras que char s[] crea una copia en la pila (stack) que sí se puede modificar.

b) ¿Por qué intentar modificar un literal de cadena es comportamiento no definido?

- Modificar char *s causa un error de memoria o violación de segmento porque se intenta escribir en una zona de memoria protegida por el sistema operativo.

c) ¿Cuándo conviene cada declaración?

- Se usa char *s cuando el texto es constante y solo se va a leer. Se prefiere char s[] cuando se necesita modificar o manipular la cadena dentro del programa.

Bloque 4 - Reserva Dinámica de Memoria

Ejercicio 4.1 Malloc vs Calloc
Respuestas:

a) ¿Cuál es la diferencia fundamental entre malloc y calloc? ¿Cuándo conviene uno u otro?

- malloc solo reserva la memoria dejando basura, por lo que conviene si vas a llenar los datos de inmediato. calloc limpia la memoria dejándola en ceros, ideal si necesitas iniciar contadores o valores limpios.

b) ¿Por qué calloc(n, size) es preferible a malloc(n * size) + memset(..., 0, ...)? (Pista: overflow en n * size.)

- Porque calloc revisa si la multiplicación n * size causa un desbordamiento (overflow). Si ocurre, devuelve NULL de forma segura, mientras que malloc reservaría un tamaño equivocado.

c) ¿Qué devuelve malloc cuando no puede reservar? ¿Cómo se maneja ese error?

- Devuelve NULL. Se maneja revisando si el puntero es NULL antes de usarlo para cortar la ejecución y evitar que el programa se caiga.

Ejercicio 4.2 Realloc - Crecimiento dinámico
Respuestas:

a) Error clásico: ¿por qué v = realloc(v, ...) directamente es peligroso si realloc retorna NULL?

- Es peligroso porque si realloc falla y retorna NULL, se pierde la dirección del arreglo original, dejando la memoria colgada sin poder liberarla.

b) ¿Qué garantiza realloc sobre el contenido previo cuando crece? ¿Y cuandodecrece?

- Al crecer garantiza conservar intactos todos los datos previos. Al decrecer mantiene solo los elementos que caben en el nuevo tamaño y descarta el resto.

c) ¿Por qué duplicar la capacidad (cap *= 2) es mejor que incrementar en 1? Analizar la complejidad total (amortized analysis).

- Duplicar reduce los reallocs y logra un costo amortizado de O(1) por inserción. Aumentar de uno en uno obliga a copiar todo en cada paso, dando una complejidad de O(n²).

d) ¿Qué pasa si realloc(ptr, 0)? ¿Es equivalente a free? (Comportamiento definido por la implementación.)

- Suele actuar como free liberando la memoria, pero depende de la implementación del compilador, por lo que es mejor usar free directamente.

Ejercicio 4.3 Diagnóstico de fugas y errores con ASan
Respuestas:

a) ¿Qué diferencia hay entre leak y double free?

- Un leak ocurre cuando se reserva memoria y no se libera al terminar de usarla, perdiendo su referencia; un double free es intentar liberar con free dos veces la misma dirección de memoria.

b) ¿Por qué el orden de free(a); free(b); no importa aquí, pero sí importa en el Bloque 3.3 con char **?

- Aquí el orden no importa porque a y b son bloques independientes en el heap. En el ejercicio 3.3 con char ** sí importa liberar primero las cadenas internas y al final el arreglo principal para no perder los punteros.

c) ¿Qué es use-after-free? Provocarlo deliberadamente y ver el reporte de ASan

- Consiste en intentar leer o escribir en una dirección de memoria que ya fue liberada con free, lo que produce comportamiento indefinido y un reporte de error inmediato en AddressSanitizer.

Bloque 1 - Arreglos Uni y Bidemensionales

1.1 Arreglo unidimensional: recorrido y estadísticas
Respuestas:

a) Declare un arreglo int datos[10] e inicialícelo con valores ingresados por el usuario (usar scanf en un for).

- Son iguales , *(datos+i) nos permite acceder a todos los elementos ya que el nombre del arreglo mismo nos de acceso a la dirección de su primer elemento y al estar sumándole 1 en cada iteración este se mueve una posición para mostrar el elemento siguiente.

b)Calcule e imprima:
o Suma, promedio (como double), mínimo, máximo.
o Cantidad de elementos pares e impares.
o Índice del máximo (el primero, si hay repetidos).

- Si se imprime sizeof(datos) se imprimiría 40 , ya que se calcula los bytes de todo el arreglo y como hay 10 elementos que son del tipo int(4 bytes) , estos se multiplican poor 10 , dando como resultado 40 ; en caso de sizeof(datos[0]) el resultado es 4 bytes , ya que datos[0] es un int y el tamaño de un int es
4 bytes.

1.2  Arreglo bidimensional: matriz y operaciones

a)Declare int m[3][4] en el stack e inicialice con valores leídos por teclado.

- Si se almacenan en un bloque contiguo de memoria, al imprimir las direcciones dadas notamos que es contiguo ya que aumenta en 4 bytes cada posición contigua
m[0][0] = 0000003E53FFFD50
m[0][1] = 0000003E53FFFD54
m[1][0] = 0000003E53FFFD60

b) Imprima la matriz alineada con printf("%4d", m[i][j]).

- No existe diferencia en cuanto al valor, se imprime el mismo valor usando cualquiera de los dos , solo que en una de ellas usamos punteros.
