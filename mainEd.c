#include <stdio.h>
#include <stdlib.h>
#include "ed.h"
#include "jugador.h"

// Función para mostrar una letra con su color correspondiente
void mostrar_letra_color(char letra, char estado) {
    if (estado == 'V') { // Verde: letra correcta
        printf("\033[0;32m%c\033[0m", letra);
    } else if (estado == 'A') { // Amarillo: letra presente en otra posición
        printf("\033[0;33m%c\033[0m", letra);
    } else if (estado == 'G') { // Gris: letra incorrecta
        printf("\033[0;37m%c\033[0m", letra);
    } else { // Color normal si no hay estado
        printf("%c", letra);
    }
}

int main() {
    int cantidad_palabras;
    char** palabras = cargar_base_datos("3.txt", &cantidad_palabras);
    
    if (palabras == NULL) {
        printf("No se pudo cargar la base de datos.\n");
        return 1;
    }

    // Aquí puedes continuar con la lógica del juego, como filtrar palabras, seleccionar palabras, etc.

    // Ejemplo de un intento y su feedback
    const char* intento = "letra";
    const char* feedback = "VGGAA"; // Ejemplo de feedback
    int cantidad_restantes;
    char** palabras_filtradas = filtrar_palabras(palabras, cantidad_palabras, intento, feedback, &cantidad_restantes);

    // Mostrar cada letra del intento con su respectivo color
    for (int i = 0; i < LARGO; i++) {
        mostrar_letra_color(intento[i], feedback[i]);
    }
    printf("\n");  // Nueva línea después de mostrar el intento

    // Aquí puedes imprimir o usar las palabras filtradas
    for (int i = 0; i < cantidad_restantes; i++) {
        printf("%s\n", palabras_filtradas[i]);
    }

    // Liberar memoria
    liberar_memoria(palabras, cantidad_palabras);
    free(palabras_filtradas);  // Si utilizaste malloc para palabras_filtradas
    return 0;
}
