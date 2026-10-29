#include <stdio.h>
#include <stdlib.h>
char *agregar_caracter(char *linea, size_t *capacidad, size_t *longitud, char c){
    if(capacidad == NULL || longitud == NULL){
        return NULL;
    }
    if(*longitud + 1 >= *capacidad){
        size_t nueva_cap = (*capacidad == 0) ? 0 : (*capacidad * 2);
        char *aux = (char *)realloc(linea, nueva_cap * sizeof(char));
        if(aux==NULL){
            return NULL;
        }
        linea=aux;
        *capacidad=nueva_cap;
    }
    linea[*longitud]=c;
    (*longitud)++;
    linea[*longitud] = '\0';

    return linea;
}

int main(void){
    char *linea=NULL;
    size_t capacidad=0;
    size_t longitud=0;
    int realloc_count=0;
    size_t historial[20];
    
    printf("Escriba algo (Enter para terminar):\n");
    
    int c;
    while((c=getchar()) != '\n' && c != EOF){
        size_t cap_anterior=capacidad;
        char *temp=agregar_caracter(linea, &capacidad,&longitud,(char)c);
        if(temp==NULL){
            printf("Error, no hay suficiente memoria.\n");
            free(linea);
            return 1;
        }
        linea=temp;
        if(capacidad>cap_anterior){
            if(cap_anterior==0){
                historial[0]=capacidad;
            }else{
                realloc_count++;
                historial[realloc_count]=capacidad;
            }
        }
    }
    if(linea==NULL){
        linea=(char *)malloc(1);
        if(linea!=NULL){
            linea[0]='\0';
        }
    }
    printf("longitud: %zu\n", longitud);
    if(realloc_count>0){
        printf("Realloc llamados: %d (", realloc_count);
        for(int i=0; i<=realloc_count;i++){
            printf("%zu%s", historial[i], (i<realloc_count) ? "->" : "");
        }
        printf(")\n");
    }else {
        printf("Realloc llamados: 0\n");
    }
    printf("Línea: \"%s\"\n", linea ? linea : "");
    free(linea);
    linea=NULL;
    return 0;
}