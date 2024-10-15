#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jugable.h"
#include "jugador.h"
#include "ed.h"

#define WORD_SIZE 4985

int main(int argc, char* argv[]) {
    char palabras[WORD_SIZE][6];
    int frecuencias[WORD_SIZE];
    int numPalabras;

    cargarBaseDeDatos(palabras, frecuencias, &numPalabras);

    if(argc != 2){
        printf("Uso: ./mainEd [palabraSecreta]\n");
        return 1;
    }

    char* palabraSecreta = argv[1];

    if (strlen(palabraSecreta) != 5){
        printf("Palabra invalida, intente de nuevo\n");
        return 1;
    }

    jugarWordle(palabraSecreta);

    return 0;
}

