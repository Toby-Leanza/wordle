#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "jugable.h"

void jugarWordle(char* palabraSecreta) {
    char *intento = (char*)malloc(6 * sizeof(char));  // Se reserva memoria para la palabra de 5 letras + terminador nulo
    if (intento == NULL) {
        printf("Error al asignar memoria.\n");
        return;
    }

    int intentos = 6;
    int adivinada = 0;  // Bandera para verificar si se ha adivinado la palabra

    for (int i = 0; i < intentos && !adivinada; i++) {
        printf("Intento %d: Ingresa una palabra de 5 letras: ", i + 1);
        scanf("%5s", intento);  // Limita la entrada a 5 caracteres para evitar desbordamientos

        // Verifica si el intento es la palabra secreta
        if (strcmp(intento, palabraSecreta) == 0) {
            printf("¡Has adivinado la palabra!\n");
            adivinada = 1;  // Marca la palabra como adivinada
        } else {
            // Muestra las letras con colores según el resultado
            for (int j = 0; j < 5; j++) {
                if (intento[j] == palabraSecreta[j]) {
                    // Letra en posición correcta - verde
                    printf(ANSI_COLOR_GREEN "%c" ANSI_COLOR_RESET, intento[j]);
                } else if (strchr(palabraSecreta, intento[j]) != NULL) {
                    // Letra en palabra pero en otra posición - amarillo
                    printf(ANSI_COLOR_YELLOW "%c" ANSI_COLOR_RESET, intento[j]);
                } else {
                    // Letra no está en la palabra - gris
                    printf(ANSI_COLOR_GRAY "%c" ANSI_COLOR_RESET, intento[j]);
                }
            }
            printf("\n");
        }
    }

    if (!adivinada) {
        printf("Lo siento, no has adivinado la palabra. La palabra secreta era: %s\n", palabraSecreta);
    }

    liberar_memoria(intento);
}

void liberar_memoria(char* palabra) {
    free(palabra);
}