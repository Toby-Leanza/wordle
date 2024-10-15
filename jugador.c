#include <stdio.h>
#include <string.h>
#include "jugador.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char* elegirPalabra(char palabras[][6], int frecuencias[], int numPalabras) {
    int maxFrecuencia = -1;
    int count = 0;

    // Primero, encontrar la máxima frecuencia
    for (int i = 0; i < numPalabras; i++) {
        if (frecuencias[i] > maxFrecuencia) {
            maxFrecuencia = frecuencias[i];
            count = 1; // Resetear contador
        } else if (frecuencias[i] == maxFrecuencia) {
            count++; // Contar palabras con la misma frecuencia
        }
    }

    // Crear un arreglo temporal para las palabras con la máxima frecuencia
    char (*palabrasMax)[6] = malloc(count * sizeof(*palabrasMax));
    int index = 0;

    // Almacenar palabras con la frecuencia máxima
    for (int i = 0; i < numPalabras; i++) {
        if (frecuencias[i] == maxFrecuencia) {
            strcpy(palabrasMax[index++], palabras[i]);
        }
    }

    // Seleccionar aleatoriamente una palabra de las palabras con máxima frecuencia
    srand(time(NULL)); // Inicializa la semilla para la generación aleatoria
    int randomIndex = rand() % count;

    // Liberar memoria y devolver la palabra elegida
    char* palabraElegida = strdup(palabrasMax[randomIndex]);
    free(palabrasMax);

    return palabraElegida;
}



void filtrarPalabras(char palabras[][6], int frecuencias[], int* numPalabras, char* intento, char resultado[5]) {
    for (int i = 0; i < *numPalabras; i++) {
        int eliminar = 0;

        for (int j = 0; j < 5; j++) {
            if (resultado[j] == 'G') { // Letra en posición correcta (verde)
                if (palabras[i][j] != intento[j]) {
                    eliminar = 1;
                }
            } else if (resultado[j] == 'Y') { // Letra en palabra, pero en posición incorrecta (amarillo)
                if (palabras[i][j] == intento[j] || !strchr(palabras[i], intento[j])) {
                    eliminar = 1;
                }
            } else { // Letra no está en la palabra (gris)
                if (strchr(palabras[i], intento[j])) {
                    eliminar = 1;
                }
            }
        }

        // Eliminar palabra de la base de datos auxiliar en memoria
        if (eliminar) {
            for (int k = i; k < *numPalabras - 1; k++) {
                strcpy(palabras[k], palabras[k + 1]);
                frecuencias[k] = frecuencias[k + 1];
            }
            (*numPalabras)--;
            i--;  // Repite la verificación para la siguiente palabra en la lista
        }
    }
}
