#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jugable.h"
#include "jugador.h"
#include "ed.h"

#define WORD_SIZE 4985

int main(int argc, char* argv[]) {
    char palabras[WORD_SIZE][6];
    int frecuencias[WORD_SIZE];  // Puedes eliminar esto si no lo usas
    int numPalabras = 0;

    cargarBaseDeDatos(palabras, frecuencias, &numPalabras);

    if (argc != 2) {
        printf("Uso: ./mainEd [palabraSecreta]\n");
        return 1;
    }

    char* palabraSecreta = argv[1];

    if (strlen(palabraSecreta) != 5) {
        printf("Palabra invalida, intente de nuevo\n");
        return 1;
    }

    // Verifica si la palabra secreta está en la lista de palabras cargadas
    int palabraValida = 0;
    for (int i = 0; i < numPalabras; i++) {
        if (strcmp(palabraSecreta, palabras[i]) == 0) {
            palabraValida = 1;
        }
    }

    if (!palabraValida) {
        printf("La palabra secreta no está en la base de datos.\n");
        return 1;
    }

    jugarWordle(palabraSecreta, palabras, frecuencias, &numPalabras);  // Pasa un puntero a numPalabras

    return 0;
}

