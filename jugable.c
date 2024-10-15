#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "jugable.h"
#include "Base_Datos.txt"

// Base de datos de palabras para recomendaciones
const char* baseDeDatos[] = {
    
};
const int numPalabrasBase = 4985; // Número de palabras en la base de datos

void jugarWordle(char* palabraSecreta) {
    char *intento = (char *)malloc(6 * sizeof(char));  // Se reserva memoria para la palabra de 5 letras + terminador nulo
    if (intento == NULL) {
        printf("Error al asignar memoria.\n");
        return;
    }

    int intentos = 6;
    int adivinada = 0;  // Bandera para verificar si se ha adivinado la palabra
    char intentosPrevios[6][6] = {""};  // Almacena los intentos previos

    for (int i = 0; i < intentos && !adivinada; i++) {
        printf("Intento %d: Ingresa una palabra de 5 letras o presiona Enter para sugerencia: ", i + 1);
        scanf("%5s", intento);  // Limita la entrada a 5 caracteres para evitar desbordamientos

        // Almacenar el intento
        strcpy(intentosPrevios[i], intento);

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

            // Proporcionar una recomendación de palabra
            printf("Recomendación de la computadora: %s\n", recomendarPalabra(intentosPrevios, i + 1));
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
