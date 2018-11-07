#pragma once
#ifndef programa_h
#define programa_h

typedef struct Move {
    char * name;
    char * move;
    int len_move;
} Move;

typedef struct Plays {
    int len;
    Move * move;
} Plays;

#endif
