#include <stdio.h>

int main(){
 int m[3][4];
 //introduzco valores
 printf("Introduzca los valores a la matriz:\n");
 for (size_t i=0;i<3;++i){
  for (size_t j=0;j<4;++j){
    scanf("%d",&m[i][j]);
  }
 }
 for (size_t i=0;i<3;++i){
  for (size_t j=0;j<4;++j){
    printf("%4d",m[i][j]);
  }
  printf("\n");
 }  
 //SUMAR CADA FILA 
 int suma,sumatotal=0;
  for (size_t i=0;i<3;++i){
    suma=0;
   for (size_t j=0;j<4;++j){
    suma=suma+m[i][j];
  }
  sumatotal=sumatotal+suma;
  printf("La suma de la fila %d es: %d\n",i+1,suma);
 }// ya se tiene la suma total
 //suma columuna
 for (size_t j=0;j<4;++j){
    suma=0;
   for (size_t i=0;i<3;++i){
    suma=suma+m[i][j];
  }
  printf("La suma de la columna %d es: %d\n",j+1,suma);
 }
printf("La suma total es: %d\n",sumatotal);
//transpuesta
int t[4][3];
for (size_t i=0;i<3;++i){
  for (size_t j=0;j<4;++j){
    t[j][i]=m[i][j];
  }
 }
 //mostrar transpuesta
 for (size_t i=0;i<4;++i){
  for (size_t j=0;j<3;++j){
    printf("%4d",t[i][j]);
  }
  printf("\n");
 } 
 int k;
 printf("Introduzca un escalar K = "); scanf("%d",&k);
 printf("La matriz original multiplicada por el escalar %d es:\n ",k);
 for (size_t i=0;i<3;++i){
  for (size_t j=0;j<4;++j){
    printf("%4d",k*m[i][j]);
  }
  printf("\n");
 }  
}
