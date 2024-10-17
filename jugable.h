#ifndef JUGABLE_H
#define JUGABLE_H

#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_GRAY    "\x1b[90m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// Función que permite jugar al juego interactivamente
void jugarWordle(char* palabraSecreta, char palabras[][6], int frecuencias[], int* numPalabras);

#endif
