#include "programa.h"
#include "lecturaArchivo.h"

Move** createPlays() {
    Move** list = (Move**)malloc(sizeof(Move*));
    return list;
}

void addMove(Move*** list,char * instr,char * r1,char * r2,char * num, int * len_array){

    Move* move = (Move*)malloc(sizeof(Move));

    move->instrucction = (char*)malloc(sizeof(char)*strlen(instr));
    move->register_1   = (char*)malloc(sizeof(char)*strlen(r1));
    move->register_2   = (char*)malloc(sizeof(char)*strlen(r2));


    strcpy(move->instrucction, instr);
    strcpy(move->register_1, r1);
    strcpy(move->register_2, r2);

    if (strcmp(instr,"sw") != 0) {
        move->number = (char*)malloc(sizeof(char)*strlen(num));
        strcpy(move->number, num);
    }
    else {
        move->number = NULL;
    }

    (*list)[*len_array] = move;

}

int checkVictory(char* board, char symbol){
    if (
    (board[0] == symbol && board[1] == symbol && board[2] == symbol)
    ||
    (board[3] == symbol && board[4] == symbol && board[5] == symbol)
    ||
    (board[6] == symbol && board[7] == symbol && board[8] == symbol)
    ||
    (board[0] == symbol && board[3] == symbol && board[6] == symbol)
    ||
    (board[1] == symbol && board[4] == symbol && board[7] == symbol)
    ||
    (board[2] == symbol && board[5] == symbol && board[8] == symbol)
    ||
    (board[0] == symbol && board[4] == symbol && board[8] == symbol)
    ||
    (board[2] == symbol && board[4] == symbol && board[6] == symbol)
    )
    {
        return 1;
    }
    return 0;
}

void printBoard(char* board, FILE* output1){
    fprintf(output1, "\n");
    for (int i = 1; i < 10; i++) {
        fprintf(output1, "%2c", board[i-1]);
        if (i != 3 && i != 6 && i != 9) {
            fprintf(output1, " |");
        }
        if (i%3 == 0) {
            fprintf(output1, "\n");
        }
    }
}

void iniciar() {

    // jugadas
    Move** plays = createPlays();
    
    // contador jugadas totales
    int len = 0;

    // pipeline
    int IF  = 0;
    int ID  = 0;
    int EX  = 0;
    int MEM = 0;
    int WB  = 0;

    // lectura jugadas
    char nombreArchivo[50];
    printf("\nIngrese nombre archivo en MIPS (con extension):\n");
    printf("> ");
    scanf("%s", nombreArchivo);
    printf("\n");
    leerArchivo(nombreArchivo, &plays, &len);
    //leerArchivo("Jugadas3.txt", &plays, &len);

    // archivos de salida
    FILE* output1;
    FILE* output2;

    output1 = fopen("Resultado.txt", "w");
    output2 = fopen("Etapas.txt", "w");

    //registro jugadores
    char* playerO = (char*)malloc(sizeof(char)*3);
    char* playerX = (char*)malloc(sizeof(char)*3);


    // tablero
    char *board;
    board = (char*)malloc (9*sizeof(char));
    for (int i=0; i<9; i++) {
        board[i] = '-';
    }

    //define jugadores
    strcpy(playerX,plays[0]->register_1);
    strcpy(playerO,plays[1]->register_1);

    for (int i = 3; i < len; i++) {
        //revision instrucciones
        if (strcmp(plays[i]->instrucction,"addi") == 0) {
            int value = atoi(plays[i]->number);

            if (board[value-1] == '-') {
                if (!strcmp(plays[i]->register_1, playerX)) {
                    board[value-1] = 'X';
                }
                else if (!strcmp(plays[i]->register_1, playerO)) {
                    board[value-1] = 'O';
                }

                IF ++;
                ID ++;
                EX ++;
                WB ++;

            }
            else {
                printf("Incompleto addi\n");
                exit(0);
            }

        }
        else if (strcmp(plays[i]->instrucction,"subi") == 0) {
            int value = atoi(plays[i]->number);

            if (board[value-1] != '-') {
                if (!strcmp(plays[i]->register_1, playerX)) {
                    if (board[value-1] != 'O') {
                        board[value-1] = '-';
                    }
                    else {
                        printf("Incompleto\n");
                        exit(0);
                    }
                }
                else if (!strcmp(plays[i]->register_1, playerO)) {
                    if (board[value-1] != 'X') {
                        board[value-1] = '-';
                    }
                    else {
                        printf("Incompleto\n");
                        exit(0);
                    }
                }

                IF ++;
                ID ++;
                EX ++;
                WB ++;
            }
            else {
                printf("Incompleto subi\n");
                exit(0);
            }
        }
        else {

            int value =atoi(strtok(plays[i]->register_2,"($sp)"));

            if (board[value/4] == '-') {
                if (!strcmp(plays[i]->register_1, playerX)) {
                    board[(value/4)] = 'X';
                }
                else if (!strcmp(plays[i]->register_1, playerO)) {
                    board[(value/4)] = 'O';
                }

                IF ++;
                ID ++;
                EX ++;
                MEM ++;
                WB ++;
            }
            else {
                printf("Incompleto sw\n");
                exit(0);
            }

        }
    }

    printBoard(board, output1);
    fprintf(output1, "\n");

    // revision resultado
    if (checkVictory(board, 'X')) {
        fprintf(output1, "Ganador jugador con registro %s (simbolo X)\n", playerX);
    }
    else if (checkVictory(board, 'O')) {
        fprintf(output1, "Ganador jugador con registro %s (simbolo O)\n", playerO);
    }
    else {
        fprintf(output1, "Empate\n");
    }

    fprintf(output2, "\nif: %d\nid: %d\nex: %d\nmem: %d\nwb: %d\n", IF, ID, EX, MEM, WB);

    fclose(output1);
    fclose(output2);

    printf("Archivos de salida generados correctamente :)\n");


}
