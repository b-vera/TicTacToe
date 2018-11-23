#pragma once
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * estructura que define la instrucción y la separa para un facil manejo
 */
typedef struct Move {
    char * instrucction;      //< campo que posee el tipo de instrucción
    char * register_1;        //< campo que posee el valor del  primer registro
    char * register_2;        //< campo que posee el valor del  segundo registro
    char * number;            //< campo que posee el valor numérico aplicado en subi y addi
} Move;

/**
 * Función que inicia el funcionamiento del programa
 */
void iniciar();

/**
 * Función en cargada de inicializar el arreglo para las estructuras
 * @return Move     list     arreglo de estructuras
 */
Move** createPlays();

/**
 * función que recibe los elementos propios de una instrucción y los organiza en una estructura
 * @param list      arreglo donde estan contenidos las estructuras
 * @param instr     valor con la instrucción
 * @param r1        valor que ingresa con el primer valor del registro
 * @param r2        valor que ingresa con el segundo valor del registro
 * @param num       valor que ingresa el número propio de instrucciones tipo addi y subi
 * @param len_array dato que entrega el largo del arreglo
 */
void addMove(Move*** list,char * instr,char * r1,char * r2,char * num, int * len_array);

/**
 * Función que comprueba si existe algún ganador en la partida
 * @param  board  tablero del juego
 * @param  symbol simblo a corroborar (X o O)
 * @return        valor que especifica si el jugador que posee ese simbolo tuvo la victoria o no
 */
int checkVictory(char* board, char symbol);

/**
 * Función que imprime el resultado con formato matricial en el archivo
 * @param board   tablero del juego
 */
void printBoard(char* board, FILE* output1);
