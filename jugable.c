#include <stdio.h>
#include <string.h>
#include "jugable.h"


void jugarWordle(char* palabraSecreta) {
    char *intento = (char*)malloc(6*sizeof(char));
    int intentos = 6;

    for (int i = 0; i < intentos; i++) {
        printf("Intento %d: Ingresa una palabra de 5 letras: ", i + 1);
        scanf("%s", intento);

        // Verifica si el intento es la palabra secreta
        if (strcmp(intento, palabraSecreta) == 0) {
            printf("¡Has adivinado la palabra!\n");
            liberar_memoria(intento);
        }

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

    printf("Lo siento, no has adivinado la palabra. La palabra secreta era: %s\n", palabraSecreta);
}

void liberar_memoria(char* palabra, int n){
    for(int i = 0; i<n; i++){
        free(palabra[i]);
    }
    free(palabra);
}