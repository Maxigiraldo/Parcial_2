#include <stdio.h>
#include <string.h>

void agregarcontacto(char listadecontactos[200][500]);
void buscarpornombre(char listadecontactos[200][500]);
void buscarpornumero(char listadecontactos[200][500]);
void eliminarcontacto(char listadecontactos[200][500]);
void mostrarcontactos(char listadecontactos[200][500]);

int main(){
    char listadecontactos[200][500];
    //ingreso usuario
    int op = 0;
    do {
        printf("\nIngrese una opcion:\n");
        printf("1. Agregar contacto nuevo.\n");
        printf("2. Buscar contacto por nombre.\n");
        printf("3. Buscar contacto por numero.\n");
        printf("4. Eliminar contacto por nombre.\n");
        printf("5. Mostrar todos los contactos.\n");
        printf("0. Salir.\n");
        scanf("%d", &op);
        switch (op){
            case 1:
                agregarcontacto(listadecontactos);
                break;
            case 2:
                buscarpornombre(listadecontactos);
                break;
            case 3:
                buscarpornumero(listadecontactos);
                break;
            case 4:
                eliminarcontacto(listadecontactos);
                break;
            case 5:
                mostrarcontactos(listadecontactos);
                break;
            case 0:
                printf("Se cerro el programa\n");
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }
    } while (op != 0);
    return 0;
}

void agregarcontacto(char listadecontactos[200][500]){
    char nombre[100];
    char apellido[100];
    char correo[100];
    char numero[100];
    printf("Ingrese el nombre del contacto: ");
    scanf("%s", nombre);
    printf("Ingrese el apellido del contacto: ");
    scanf("%s", apellido);
    printf("Ingrese el correo: ");
    scanf("%s", correo);
    printf("Ingrese el numero del contacto: ");
    scanf("%s", numero);
    int i = 0;
    while (listadecontactos[i][0] != '\0'){
        i += 4;
    }
    strcpy(listadecontactos[i], nombre);
    strcpy(listadecontactos[i + 1], apellido);
    strcpy(listadecontactos[i + 2], correo);
    strcpy(listadecontactos[i + 3], numero);
    printf("Contacto agregado exitosamente\n");
}

void buscarpornombre(char listadecontactos[200][500]){
    char nombre[100];
    printf("Ingrese el nombre del contacto: ");
    scanf("%s", nombre);
    int i = 0;
    while (listadecontactos[i][0] != '\0'){
        if (strcmp(listadecontactos[i], nombre) == 0){
            printf("Nombre: %s\n", listadecontactos[i]);
            printf("Apellido: %s\n", listadecontactos[i + 1]);
            printf("Correo: %s\n", listadecontactos[i + 2]);
            printf("Numero: %s\n", listadecontactos[i + 3]);
            return;
        }
        i++;
    }
    printf("Contacto no encontrado\n");
}

void buscarpornumero(char listadecontactos[200][500]){
    char numero[100];
    printf("Ingrese el numero del contacto: ");
    scanf("%s", numero);
    int i = 0;
    while (listadecontactos[i][0] != '\0'){
        if (strcmp(listadecontactos[i + 3], numero) == 0){
            printf("Nombre: %s\n", listadecontactos[i]);
            printf("Apellido: %s\n", listadecontactos[i + 1]);
            printf("Correo: %s\n", listadecontactos[i + 2]);
            printf("Numero: %s\n", listadecontactos[i + 3]);
            return;
        }
        i++;
    }
    printf("Contacto no encontrado\n");
}

void eliminarcontacto(char listadecontactos[200][500]){
    char nombre[100];
    printf("Ingrese el nombre del contacto: ");
    scanf("%s", nombre);
    int i = 0;
    while (listadecontactos[i][0] != '\0'){
        if (strcmp(listadecontactos[i], nombre) == 0){
            listadecontactos[i][0] = 'x';
            listadecontactos[i + 1][0] = 'x';
            listadecontactos[i + 2][0] = 'x';
            listadecontactos[i + 3][0] = 'x';
            printf("Contacto eliminado exitosamente\n");
            return;
        }
        i++;
    }
    printf("Contacto no encontrado\n");
}

void mostrarcontactos(char listadecontactos[200][500]){
    int i = 0;
    while (listadecontactos[i][0] != '\0'){
        if (listadecontactos[i][0] == 'x'){
            i += 4;
        }
        else { 
            printf("Nombre: %s\n", listadecontactos[i]);
            printf("Apellido: %s\n", listadecontactos[i + 1]);
            printf("Correo: %s\n", listadecontactos[i + 2]);
            printf("Numero: %s\n", listadecontactos[i + 3]);
            printf("\n");
            i += 4;
        }
    }
}