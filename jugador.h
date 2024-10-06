#ifndef JUGADOR_H
#define JUGADOR_H

#define INTENTOS 6
#define LARGO 5
#define MAX_PALABRAS 4985

#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define reset "\e[0m"

// Función para filtrar las palabras según las pistas
char** filtrar_palabras(char palabras[][LARGO + 1], int cantidad_palabras, const char* intento, const char* feedback, int* cantidad_restantes);

// Función para seleccionar la palabra
char* seleccionar_palabra(char palabras[][LARGO + 1], int cantidad_palabras);

// Función para liberar la memoria usada por las palabras
void liberar_memoria(char** palabras, int cantidad_palabras);

#endif
