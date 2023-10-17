#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
    srand(time(NULL));

    //generar matrices
    int n = 0;
    printf("Ingrese el tamaño de la matriz de 2x2 o 3x3: ");
    scanf("%d", &n);
    if (n != 2 && n != 3){
        printf("El tamaño de la matriz debe ser 2x2 o 3x3\n");
        return 0;
    }
    int matriz1[n][n];
    int matriz2[n][n];

    //dar valores a la matriz
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matriz1[i][j] = rand() % 10;
        }
    }
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matriz2[i][j] = rand() % 10;
        }
    }

    //mostrar matriz
    printf("Matriz 1:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d\t", matriz1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Matriz 2:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d\t", matriz2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    //multiplicar matrices
    int matrizproducto[n][n];
    int suma = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            suma = 0;
            for(int k = 0; k < n; k++){
                suma += matriz1[i][k] * matriz2[k][j];
            }
            matrizproducto[i][j] = suma;
        }
    }
    //mostrar matriz
    printf("Matriz producto:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d\t", matrizproducto[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //determinante de la matriz1
    int determinante = 0;
    if (n == 2){
        determinante = (matriz1[0][0] * matriz1[1][1]) - (matriz1[0][1] * matriz1[1][0]);
    }
    else{
        determinante = (matriz1[0][0] * ((matriz1[1][1] * matriz1[2][2]) - (matriz1[1][2] * matriz1[2][1]))) - (matriz1[0][1] * ((matriz1[1][0] * matriz1[2][2]) - (matriz1[1][2] * matriz1[2][0]))) + (matriz1[0][2] * ((matriz1[1][0] * matriz1[2][1]) - (matriz1[1][1] * matriz1[2][0])));
    }
    printf("Determinante de la matriz 1: %d\n", determinante);

    //inversa de la matriz1
    if (determinante != 0) {
        double matrizinversa[n][n];
        // Copiar matriz1 a matrizinversa
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) { 
                    matrizinversa[i][j] = 1.0;
                }   
                else {
                    matrizinversa[i][j] = 0.0;
                }
            }
        }

        for (int k = 0; k < n; k++) {
            double pivot = matriz1[k][k];
            for (int j = 0; j < n; j++) {
                matriz1[k][j] /= pivot;
                matrizinversa[k][j] /= pivot;
            }
            for (int i = 0; i < n; i++) {
                if (i != k) {
                    double factor = matriz1[i][k];
                    for (int j = 0; j < n; j++) {
                        matriz1[i][j] -= factor * matriz1[k][j];
                        matrizinversa[i][j] -= factor * matrizinversa[k][j];
                    }
                }
            }
        }

        // Mostrar matriz inversa con mayor precisión
        printf("Matriz 1 inversa:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%.4lf\t", matrizinversa[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("La matriz no tiene inversa\n");
    }

    //determinante de la matriz2
    determinante = 0;
    if (n == 2){
        determinante = (matriz2[0][0] * matriz2[1][1]) - (matriz2[0][1] * matriz2[1][0]);
    }
    else{
        determinante = (matriz2[0][0] * ((matriz2[1][1] * matriz2[2][2]) - (matriz2[1][2] * matriz2[2][1]))) - (matriz2[0][1] * ((matriz2[1][0] * matriz2[2][2]) - (matriz2[1][2] * matriz2[2][0]))) + (matriz2[0][2] * ((matriz2[1][0] * matriz2[2][1]) - (matriz2[1][1] * matriz2[2][0])));
    }
    printf("Determinante de la matriz 2: %d\n", determinante);
    //matriz elevada a k
    int k = 0;
    printf("Ingrese el valor de k: ");
    scanf("%d", &k);
    int matrizk[n][n];
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrizk[i][j] = matriz2[i][j];
        }
    }

    int matrizTemporal[n][n]; 

    for (int l = 1; l < k; l++){ 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                suma = 0;
                for(int m = 0; m < n; m++){
                    suma += matrizk[i][m] * matriz2[m][j];
                }
                matrizTemporal[i][j] = suma; 
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                matrizk[i][j] = matrizTemporal[i][j];
            }
        }
    }

    //mostrar matriz elevada a k
    printf("Matriz 2 elevada a k:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d\t", matrizk[i][j]);
        }
        printf("\n");
    }
    return 0;
}