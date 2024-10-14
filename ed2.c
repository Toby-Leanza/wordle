#include <stdio.h>
#include "ed2.h"

void mostrarLetrasRestantes(int intentadas[]) {
    printf("Letras restantes: ");
    for (char letra = 'a'; letra <= 'z'; letra++) {
        if (!intentadas[letra - 'a']) {
            printf("%c ", letra);
        }
    }
    printf("\n");
}
