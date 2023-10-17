#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    //generar vector
    int n = 0;
    printf("Ingrese el tamaño del vector: ");
    scanf("%d", &n);
    int vector[n];
    //dar valores al vector
    for(int i = 0; i < n; i++){
        vector[i] = rand() % 11;
    }
    //mostrar vector
    printf("Vector: ");
    for(int i = 0; i < n; i++){
        printf("%d ", vector[i]);
    }
    printf("\n");
    //buscar las duplas
    int duplas = 0;
    int suma = 0;
    int par = 0;
    int impar = 0;
    for (int i = 0; i < n; i++){
        if(vector[i] == vector[i+1]){
            duplas++;
            printf("Suma dupla %d: %d + %d\t", duplas, vector[i], vector[i+1]);
            suma = (vector[i] * vector[i + 1]) + 1;
            printf("%d\n",  suma);
            if (suma % 2 == 0){
                par++;
                vector[i] = suma;
            }
            else{
                impar++;
                vector[i + 1] = suma;
            }
        }
    }
    //mostrar vector modificado
    printf("Vector: ");
    for(int i = 0; i < n; i++){
        printf("%d ", vector[i]);
    }
    printf("\n");
    //mostrar resultados
    printf("Duplas: %d\n", duplas);
    printf("Suma par: %d\n", par);
    printf("Suma impar: %d\n", impar);
    return 0;
}