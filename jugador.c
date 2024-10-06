#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jugador.h"

// Función para filtrar las palabras según las pistas
char** filtrar_palabras(char palabras[][LARGO + 1], int cantidad_palabras, const char* intento, const char* feedback, int* cantidad_restantes) {
    char** filtradas = (char**)malloc(cantidad_palabras * sizeof(char*));
    if (!filtradas) {
        printf("Error de memoria\n");
        return NULL;
    }

    *cantidad_restantes = 0;

    for (int i = 0; i < cantidad_palabras; i++) {
        int valida = 1;

        for (int j = 0; j < LARGO; j++) {
            if (feedback[j] == 'V') {  // Verde: la letra está en la posición correcta
                valida = valida && (palabras[i][j] == intento[j]);
            } else if (feedback[j] == 'A') {  // Amarillo: la letra está en la palabra pero en otra posición
                valida = valida && (palabras[i][j] != intento[j]) && (strchr(palabras[i], intento[j]));
            } else if (feedback[j] == 'G') {  // Gris: la letra no está en la palabra
                valida = valida && (!strchr(palabras[i], intento[j]));
            }
        }

        if (valida) {
            filtradas[*cantidad_restantes] = palabras[i];
            (*cantidad_restantes)++;
        }
    }

    return filtradas;
}

// Función para seleccionar la palabra
char* seleccionar_palabra(char palabras[][LARGO + 1], int cantidad_palabras) {
    if (cantidad_palabras == 0) {
        return NULL;  // No hay palabras posibles
    }

    // Aquí puedes agregar la lógica para seleccionar la mejor palabra (en este caso, puedes usar el primer elemento)
    return palabras[0];  // Cambia esta lógica según tus necesidades
}

// Función para liberar la memoria usada por las palabras
void liberar_memoria(char** palabras, int cantidad_palabras) {
    for (int i = 0; i < cantidad_palabras; i++) {
        free(palabras[i]);
    }
    free(palabras);
}
