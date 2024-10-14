#include <stdio.h>
#include "jugable.h"
#include "jugador.h"
#include "ed.h"

#define WORD_SIZE 5

int main() {
    char palabras[WORD_SIZE][6];
    int frecuencias[WORD_SIZE];
    int numPalabras;

    cargarBaseDeDatos(palabras, frecuencias, &numPalabras);

    // Seleccionar una palabra secreta
    char* palabraSecreta = elegirPalabra(palabras, frecuencias, numPalabras);

    // Comenzar el juego
    jugarWordle(palabraSecreta);

    return 0;
}
