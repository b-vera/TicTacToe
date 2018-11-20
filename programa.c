#include "programa.h"
#include "lecturaArchivo.h"

Plays * createPlays() {
    Plays * list = (Plays *)malloc(sizeof(Plays));
    list->len  = 0;
    list->move_i = NULL;
    list->move_r = NULL;
    return list;
}

void addMoveR(Plays * list,char * instr,char * r1,char * r2,char * num){

    Move_R * value = (Move_R *)malloc(sizeof(Move_R));

    value -> instrucction = instr;
    value -> register_1 = r1;
    value -> register_2 = r2;
    value -> number = num;
}

void addMoveI(Plays * list,char * instr,char * r1 ,char * num){

    Move_I * value = (Move_I *)malloc(sizeof(Move_I));

    value -> instrucction = instr;
    value -> register_1 = r1;
    value -> number = num;
}

void iniciar(){
    Plays * plays = createPlays();
    leerArchivo("prueba.txt",plays);
}
