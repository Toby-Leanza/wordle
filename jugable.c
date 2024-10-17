#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "jugable.h"
#include "jugador.h"

void jugarWordle(char* palabraSecreta, char palabras[][6], int frecuencias[], int* numPalabras) {
    char *intento = (char*)malloc(6 * sizeof(char));  // Memoria para la palabra de 5 letras + terminador nulo
    if (intento == NULL) {
        printf("Error al asignar memoria.\n");
        return;
    }

    int intentos = 6;
    int adivinada = 0;  // Bandera para verificar si se ha adivinado la palabra
    char resultado[5];  // Array para almacenar el resultado (G, Y, X)

    for (int i = 0; i < intentos && !adivinada; i++) {
        do {
            printf("Ingresa una palabra de 5 letras (%d intentos restantes): \n", 6 - i);
            scanf("%5s", intento);  // Limita la entrada a 5 caracteres

            if (strlen(intento) != 5) {
                printf("\nError: La palabra debe tener exactamente 5 letras. Intenta de nuevo.\n");
            }
        } while (strlen(intento) != 5); // Repetir si la palabra no tiene 5 letras

        // Verifica si el intento es la palabra secreta
        if (strcmp(intento, palabraSecreta) == 0) {
            printf("\n¡Has adivinado la palabra!\n");
            adivinada = 1;  // Marca la palabra como adivinada
        } else {
            // Muestra las letras con colores según el resultado
            for (int j = 0; j < 5; j++) {
                if (intento[j] == palabraSecreta[j]) {
                    resultado[j] = 'G';  // Letra en posición correcta
                    printf(ANSI_COLOR_GREEN "%c" ANSI_COLOR_RESET, intento[j]);
                } else if (strchr(palabraSecreta, intento[j]) != NULL) {
                    resultado[j] = 'Y';  // Letra en palabra, pero en posición incorrecta
                    printf(ANSI_COLOR_YELLOW "%c" ANSI_COLOR_RESET, intento[j]);
                } else {
                    resultado[j] = 'X';  // Letra no está en la palabra
                    printf(ANSI_COLOR_GRAY "%c" ANSI_COLOR_RESET, intento[j]);
                }
            }
            printf("\n");

            // Filtrar palabras después de cada intento
            filtrarPalabras(palabras, frecuencias, numPalabras, intento, resultado);

            // Mostrar solo la primera sugerencia posible
            if (*numPalabras > 0) {
                printf("Sugerencia posible: %s\n", palabras[0]);  // Solo muestra la primera sugerencia
            } else {
                printf("\nNo hay sugerencias disponibles.\n");
            }
        }
    }

    if (!adivinada) {
        printf("\nLo siento, no has adivinado la palabra. La palabra secreta era: %s\n", palabraSecreta);
    }

    free(intento);
}


