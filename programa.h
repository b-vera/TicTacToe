#pragma once
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Move {
    char * instrucction;
    char * register_1;
    char * register_2;
    char * number;
} Move;

void iniciar();
Move** createPlays();
void addMove(Move*** list,char * instr,char * r1,char * r2,char * num, int * len_array);
