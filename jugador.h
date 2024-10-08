#ifndef JUGADOR_H
#define JUGADOR_H

// Función que elige una palabra de la base de datos según la frecuencia
char* elegirPalabra(char palabras[][6], int frecuencias[], int numPalabras);

// Función que filtra palabras según las reglas del juego
void filtrarPalabras(char palabras[][6], int frecuencias[], int* numPalabras, char* intento, char resultado[5]);

#endif
