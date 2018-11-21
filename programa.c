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

void checkVictory(char** board,char * player){
    if ( ((strcmp(&board[0][0],&board[0][1]) == 0) && (strcmp(&board[0][1],&board[0][2]) == 0)) ||
    ((strcmp(&board[1][0],&board[1][1]) == 0) && (strcmp(&board[1][1],&board[1][2]) == 0)) ||
    ((strcmp(&board[2][0],&board[2][1]) == 0) && (strcmp(&board[2][1],&board[2][2]) == 0)) ||
    ((strcmp(&board[0][0],&board[1][0]) == 0) && (strcmp(&board[1][0],&board[2][0]) == 0)) ||
    ((strcmp(&board[0][1],&board[1][1]) == 0) && (strcmp(&board[1][1],&board[2][1]) == 0)) ||
    ((strcmp(&board[0][2],&board[1][2]) == 0) && (strcmp(&board[1][2],&board[2][2]) == 0)) ||
    ((strcmp(&board[0][0],&board[1][1]) == 0) && (strcmp(&board[1][1],&board[2][2]) == 0)) ||
    ((strcmp(&board[2][0],&board[1][1]) == 0) && (strcmp(&board[1][1],&board[0][2]) == 0)) ) {
        printf("Ganador jugador con registro %s\n",player);
    } else {
        printf("Empate\n");
    }
}

void printBoard(char** board){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 2) {
                printf(" %2C",board[i][j]);
            } else {
                printf(" %2C |",board[i][j]);
            }
        }
        printf("\n");
    }
}

void iniciar() {

    Move** plays = createPlays();
    int len = 0;
    leerArchivo("Jugadas3.txt", &plays, &len);

    //registro jugadores
    char* playerO = (char*)malloc(sizeof(char)*3);
    char* playerX = (char*)malloc(sizeof(char)*3);

    int count; //contador de jugadas totales


    // tablero
    char **board;
    board = (char **)malloc (3*sizeof(char *));
    for (int i=0;i<3;i++)
        board[i] = (char *) malloc (3*sizeof(char));


    for (int i = 0; i < len; i++) {
        printf("%s %s %s %s\n", plays[i]->instrucction, plays[i]->register_1, plays[i]->register_2,plays[i]->number);

        //define jugadores
        if (i == 0) {
            strcpy(playerO,plays[i]->register_1);
            printf("player_O= %s\n",playerO );
        } else if (i == 1) {
            strcpy(playerX,plays[i]->register_1);
            printf("player_X= %s\n",playerX );

        } else {

            //revision instrucciones
            if (strcmp(plays[i]->instrucction,"addi") == 0) {
                int value = atoi(plays[i]->number);

                char * var = (char*)malloc(sizeof(char));
                if (strcmp(plays[i]->register_1,playerX)) {
                    strcpy(var,"X");
                }else if (strcmp(plays[i]->register_1,playerO)) {
                    strcpy(var,"O");
                }

                switch (value) {
                    case 1:
                        strcpy(&board[0][0],var);
                        break;
                    case 2:
                        strcpy(&board[0][1],var);
                        break;
                    case 3:
                        strcpy(&board[0][2],var);
                        break;
                    case 4:
                        strcpy(&board[1][0],var);
                        break;
                    case 5:
                        strcpy(&board[1][1],var);
                        break;
                    case 6:
                        strcpy(&board[1][2],var);
                        break;
                    case 7:
                        strcpy(&board[2][0],var);
                        break;
                    case 8:
                        strcpy(&board[2][1],var);
                        break;
                    case 9:
                        strcpy(&board[2][2],var);
                        break;
                    default:
                        break;
                }
            } else if (strcmp(plays[i]->instrucction,"subi") == 0) {
                int value = atoi(plays[i]->number);
                switch (value) {
                    case 1:
                        strcpy(&board[0][0],"0");
                        break;
                    case 2:
                            strcpy(&board[0][1],"0");
                            break;
                    case 3:
                            strcpy(&board[0][2],"0");
                            break;
                    case 4:
                            strcpy(&board[1][0],"0");
                            break;
                    case 5:
                            strcpy(&board[1][1],"0");
                            break;
                    case 6:
                            strcpy(&board[1][2],"0");
                            break;
                    case 7:
                            strcpy(&board[2][0],"0");
                            break;
                    case 8:
                            strcpy(&board[2][1],"0");
                            break;
                    case 9:
                            strcpy(&board[2][2],"0");
                            break;
                }
            } else {
                int value =atoi(strtok(plays[i]->register_2,"($sp)"));

                char * var = (char*)malloc(sizeof(char));
                if (strcmp(plays[i]->register_1,playerX)) {
                    strcpy(var,"X");
                }else if (strcmp(plays[i]->register_1,playerO)) {
                    strcpy(var,"O");
                }

                switch (value) {
                    case 0:
                        strcpy(&board[0][0],var);
                        break;
                    case 4:
                        strcpy(&board[0][1],var);
                        break;
                    case 8:
                        strcpy(&board[0][2],var);
                        break;
                    case 12:
                        strcpy(&board[1][0],var);
                        break;
                    case 16:
                        strcpy(&board[1][1],var);
                        break;
                    case 20:
                        strcpy(&board[1][2],var);
                        break;
                    case 24:
                        strcpy(&board[2][0],var);
                        break;
                    case 28:
                        strcpy(&board[2][1],var);
                        break;
                    case 32:
                        strcpy(&board[2][2],var);
                        break;
                }
            }
        }

        printf("\n");
        printBoard(board);
        printf("\n");

    }
    // printBoard(board);
}
