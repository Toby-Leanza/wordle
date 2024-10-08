#include <stdio.h>
#include "ed.h"

void cargarBaseDeDatos(char palabras[][6], int frecuencias[], int* numPalabras) {
    FILE *archivo = fopen("palabras.txt", "r");

    if (!archivo) {
        printf("No se pudo abrir el archivo de palabras.\n");
        return;
    }

    int i = 0;
    while (fscanf(archivo, "%s %d", palabras[i], &frecuencias[i]) != EOF) {
        i++;
    }
    *numPalabras = i;
    
    fclose(archivo);
}
