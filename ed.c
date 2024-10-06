#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ed.h"

#define LARGO 5
#define MAX_PALABRAS 4985

#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define reset "\e[0m"

// Función para cargar la base de datos de palabras desde un archivo
char** cargar_base_datos(const char* nombre_archivo, int* cantidad_palabras) {
    FILE* archivo = fopen(nombre_archivo, "r");
    if (!archivo) {
        printf("Error al abrir el archivo %s\n", nombre_archivo);
        return NULL;
    }

    // Reservar espacio para el arreglo de palabras
    char** palabras = (char**)malloc(MAX_PALABRAS * sizeof(char*));
    if (!palabras) {
        printf("Error de memoria\n");
        fclose(archivo);
        return NULL;
    }

    *cantidad_palabras = 0;
    char buffer[LARGO + 1];

    // Leer palabras del archivo, una palabra por línea
    while (fscanf(archivo, "%5s", buffer) != EOF) {
        palabras[*cantidad_palabras] = strdup(buffer);  // Duplicar la cadena
        (*cantidad_palabras)++;

        if (*cantidad_palabras >= MAX_PALABRAS) {
            break;
        }
    }

    fclose(archivo);
    return palabras;
}
