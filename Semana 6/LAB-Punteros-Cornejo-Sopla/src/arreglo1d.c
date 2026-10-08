#include <stdio.h>
#define SIZE 10
int main(){
 int datos[SIZE];
 printf("Ingrese los valores :\n");
 for (size_t i=0;i<SIZE;++i){
   scanf("%d",&datos[i]);
 }
 int suma=0,minimo=999999,maximo=0;
 double promedio;
//CALCULO DE SUMA Y PROMEDIO 
for (size_t i=0;i<SIZE;++i){
     suma=suma+ datos[i];
 }
promedio=suma/SIZE;
// calculo maximo 
for (size_t i=0;i<SIZE;++i){
   if(datos[i]>maximo){
    maximo=datos[i];
   }
 }
 //calculo minimo
for (size_t i=0;i<SIZE;++i){
   if(datos[i]<minimo){
    minimo=datos[i];
   }
 }
 //CANT ELEMENTOS PARES E IMPARES
 int cpares=0,cimpares;
 for (size_t i=0;i<SIZE;++i){
   if(datos[i]%2==0){
      cpares++;
   }
 }
 cimpares=SIZE-cpares;
 //INDICE DEL MAXIMO 
 int indice;
for (size_t i=0;i<SIZE;++i){
   if(datos[i]==maximo){
      indice=i;
      break;
   }
 }
printf("Suma: %d\n",suma);
printf("Promedioa : %f\n",promedio);
printf("Minimo: %d\n",minimo);
printf("Maximo: %d (indice %d)\n",maximo,indice);
printf("Pares: %d\n",cpares);
printf("Impares: %d\n",cimpares);
printf("Original:");
for (size_t i=0;i<SIZE;++i){
    if(i!=SIZE-1){
        printf(" %d,",datos[i]); 
    }
    else {
        printf(" %d\n",datos[i]);
    }
 }
 //INVERTIR ARREGLO 
 for (size_t i=0;i<SIZE/2;++i){
    int aux=datos[i];
   datos[i]=datos[SIZE-(i+1)];
   datos[SIZE-(i+1)]=aux;
 }
 printf("Invertido:");
for (size_t i=0;i<SIZE;++i){
    if(i!=SIZE-1){
        printf(" %d,",datos[i]); 
    }
    else {
        printf(" %d",datos[i]);
    }
 }
}