#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jugable.h"
#include "jugador.h"
#include "ed.h"

#define WORD_SIZE 4985

int main() {
    char palabras[WORD_SIZE][6];
    int frecuencias[WORD_SIZE];
    int numPalabras;

    cargarBaseDeDatos(palabras, frecuencias, &numPalabras);

    // Seleccionar una palabra secreta
    char* palabraSecreta = elegirPalabra(palabras, frecuencias, numPalabras);

    // Comenzar el juego
    jugarWordle(palabraSecreta);

    // Liberar la palabra secreta
    liberar_memoria(palabraSecreta);

    return 0;
}

