#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    //ingreso de la cadena
    char cadena[500] = "No sabia cuando y como llegue al mundo sombra como en un lugar de luz ahora solo veia oscuridad como antes sentia la calida brisa del verano abrazando mi cuerpo y ahora siento el frio de un invierno sin proposito de parar o dejar entrar un poco de luz";
    //printf("Ingrese una cadena: ");
    //fgets(cadena, 100, stdin);
    int longitud = strlen(cadena);
    if (cadena[strlen(cadena) - 1] == '\n'){
        cadena[strlen(cadena) - 1] = '\0';
    }
    //palabras y caracteres de la cadena
    int palabras = 0;
    for (int i = 0; i < longitud; i++){
        if (cadena[i] == ' '){
            palabras++;
        }
    }
    printf("Palabras: %d\n", palabras + 1);
    printf("Caracteres: %d\n", longitud + 1);
    
    //buscar la palabra mas corta de la cadena
    char palabracorta[300];
    char palabraactual[300];
    int i = 0, j;
    int longitudpalabra = longitud;

    while (i < longitud) {
        j = 0;
        while (cadena[i] != ' ' && cadena[i] != '\0') {
            palabraactual[j] = cadena[i];
            i++;
            j++;
        }
        palabraactual[j] = '\0';

        if (strlen(palabraactual) < longitudpalabra) {
            longitudpalabra = strlen(palabraactual);
            strcpy(palabracorta, palabraactual);
        }

        i++; 
    }

    printf("Palabra mas corta: %s\n", palabracorta);
    
    //buscar la palabra mas larga de la cadena
    char palabralarga[300];
    i = 0;
    longitudpalabra = 0; 

    while (i < longitud) {
        j = 0;
        while (cadena[i] != ' ' && cadena[i] != '\0') {
            palabraactual[j] = cadena[i];
            i++;
            j++;
        }
        palabraactual[j] = '\0';

        if (strlen(palabraactual) > longitudpalabra) {
            longitudpalabra = strlen(palabraactual);
        }
        i++; 
    }
    i = 0;
    while (i < longitud){
        j = 0;
        while (cadena[i] != ' ' && cadena[i] != '\0'){
            palabraactual[j] = cadena[i];
            i++;
            j++;
        }
        palabraactual[j] = '\0';
        if (strlen(palabraactual) == longitudpalabra){
            strcat(palabralarga, " ");
            strcat(palabralarga, palabraactual);
        }
        i++;
    }
    printf("Palabra mas larga: %s\n", palabralarga);
    printf("Caracteres palabra larga: %d\n", longitudpalabra);

    //buscar la palabra que no se repite
    char palabraactual2[300];
    int repetidos = 0;
    i = 0;
    int l = 0;
    int k = 0;
    printf("Palabra unicas:\n");
    do {
        j = 0;
        while (cadena[i] != ' ' && cadena[i] != '\0') {
            palabraactual[j] = cadena[i];
            i++;
            j++;
        }
        palabraactual[j] = '\0';
        l = 0;
        repetidos = 0;
        k = 0;
        while (k < longitud){
            l = 0;
            while(cadena[k] != ' ' && cadena[k] != '\0'){
                palabraactual2[l] = cadena[k];
                k++;
                l++;
            }
            palabraactual2[l] = '\0';
            if (strcmp(palabraactual, palabraactual2) == 0){
                repetidos++;
            }
            k++;
        }
        if (repetidos == 1){
            printf("%s\t", palabraactual);
        }
        i++;
    } while(i < longitud);

    //palabra que se repite
    repetidos = 0;
    char cadenacopia[500];
    strcpy(cadenacopia, cadena);
    i = 0;
    l = 0;
    k = 0;
    printf("\nPalabra repetida:\n");
    do {
        j = 0;
        while (cadenacopia[i] != ' ' && cadenacopia[i] != '\0') {
            palabraactual[j] = cadenacopia[i];
            i++;
            j++;
        }
        palabraactual[j] = '\0';
        l = 0;
        repetidos = 0;
        k = 0;
        while (k < longitud){
            l = 0;
            while(cadenacopia[k] != ' ' && cadenacopia[k] != '\0'){
                palabraactual2[l] = cadenacopia[k];
                k++;
                l++;
            }
            palabraactual2[l] = '\0';
            if (strcmp(palabraactual, palabraactual2) == 0){
                repetidos++;
            }
            k++;
        }
        if (repetidos > 1){
            printf("%s\t", palabraactual);
        }
        i++;
    } while(i < longitud);
    return 0;
}