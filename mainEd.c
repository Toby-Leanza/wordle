#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "jugable.h"
#include "jugador.h"
#include "ed.h"

#define WORD_SIZE 4985

int main() {
    char palabras[WORD_SIZE][6];  // Base de datos auxiliar con 4985 palabras
    int frecuencias[WORD_SIZE];    // Frecuencias correspondientes a cada palabra
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

