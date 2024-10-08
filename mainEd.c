#include <stdio.h>
#include "jugable.h"
#include "jugador.h"
#include "ed.h"

int main() {
    char palabras[][6];
    int frecuencias[];
    int numPalabras;

    cargarBaseDeDatos(palabras, frecuencias, &numPalabras);

    // Seleccionar una palabra secreta
    char* palabraSecreta = elegirPalabra(palabras, frecuencias, numPalabras);

    // Comenzar el juego
    jugarWordle(palabraSecreta);

    return 0;
}
