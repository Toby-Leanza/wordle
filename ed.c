#include <stdio.h>
#include "ed.h"

void cargarBaseDeDatos(char palabras[][6], int frecuencias[], int* numPalabras) {
    FILE *archivo = fopen("Base_Datos.txt", "r");

    if (!archivo) {
        printf("No se pudo abrir el archivo de palabras.\n");
        return;
    }

    int i = 0;
    // Asegúrate de que la cadena puede contener 5 letras más el terminador nulo.
    while (fscanf(archivo, "%5[^,],%d\n", palabras[i], &frecuencias[i]) != EOF) {
        i++;
    }
    *numPalabras = i;
    
    fclose(archivo);
}

