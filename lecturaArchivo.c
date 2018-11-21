#include "lecturaArchivo.h"

void leerArchivo(char * nombreArchivo, Move*** plays, int * len_array) {

    FILE * file;
    char * pch;
    char line[100];

    char * instrucction = NULL;
    char * register_1 = NULL;
    char * register_2 = NULL;
    char * number = NULL;

    file = fopen(nombreArchivo, "r");
    if (file == NULL){
        exit(0);
    }

    while (fgets(line, 100, file)) {

        pch = strtok (line," ,");

        if (strcmp(pch,"addi") == 0 || strcmp(pch,"subi") == 0) {

            instrucction = (char*)malloc(sizeof(char)*strlen(pch));
            strcpy(instrucction, pch);

            pch = strtok (NULL, " ");
            register_1 = (char*)malloc(sizeof(char)*strlen(pch));
            strcpy(register_1, pch);

            pch = strtok (NULL, ", ");
            register_2 = (char*)malloc(sizeof(char)*strlen(pch));
            strcpy(register_2, pch);

            pch = strtok (NULL, ", \n");
            number = (char*)malloc(sizeof(char)*strlen(pch));
            strcpy(number, pch);

            (*plays) = (Move**)realloc((*plays),((* len_array)+1)*sizeof(Move*));
            addMove(plays,instrucction,register_1,register_2,number,len_array);
            (*len_array) = (*len_array) + 1;

        }

        else if(strcmp(pch,"sw") == 0) {

            instrucction = (char*)malloc(sizeof(char)*strlen(pch));
            strcpy(instrucction, pch);

            pch = strtok (NULL, " ");
            register_1 = (char*)malloc(sizeof(char)*strlen(pch));
            strcpy(register_1, pch);

            pch = strtok (NULL, ", \n");
            register_2 = (char*)malloc(sizeof(char)*strlen(pch));
            strcpy(register_2, pch);

            (*plays) = (Move**)realloc((*plays),((* len_array)+1)*sizeof(Move*));
            addMove(plays,instrucction,register_1,register_2,number,len_array);
            (*len_array) = (*len_array) + 1;
        }

    }

    fclose(file);

    free(instrucction);
    free(register_1);
    free(register_2);
    free(number);

    return;
}
