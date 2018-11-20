#pragma once
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Move_R {
    char * instrucction;
    char * register_1;
    char * register_2;
    char * number;
} Move_R;

typedef struct Move_I {
    char * instrucction;
    char * register_1;
    char * number;
} Move_I;

typedef struct Plays {
    int len;
    Move_I * move_i;
    Move_R * move_r;
} Plays;

void iniciar();
Plays * createPlays();
void addMoveR(Plays * list,char * instr,char * r1,char * r2,char * num);
void addMoveI(Plays * list,char * instr,char * r1 ,char * num);
