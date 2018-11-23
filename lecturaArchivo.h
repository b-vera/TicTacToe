#pragma once
#include "programa.h"

/**
 * Función encargada de la lectura del archivo en sus respectivas instrucciones
 * y la separación de estas para agregarlas dentro de una estructura
 * @param nombreArchivo nombre del archivo de entrada
 * @param plays         arreglo de jugadas
 * @param len_array     largo del arreglo
 */
void leerArchivo(char * nombreArchivo, Move*** plays, int* len_array);
