#include <stdio.h>
#include "ed2.h"

void registrarIntento(char letra, int intentadas[]) {
    intentadas[letra - 'a'] = 1;  // Marca la letra como intentada
}

void mostrarLetrasRestantes(int intentadas[]) {
    printf("Letras restantes: ");
    for (char letra = 'a'; letra <= 'z'; letra++) {
        if (!intentadas[letra - 'a']) {
            printf("%c ", letra);
        }
    }
    printf("\n");
}
