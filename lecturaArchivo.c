#include "lecturaArchivo.h"

void leerArchivo(char * nombreArchivo, Plays * plays) {
    FILE * fp;
    char * line = NULL;
    char * pch;
    size_t len = 0;
    ssize_t read;

    int count;

    char * instrucction;
    char * register_1;
    char * register_2;
    char * number;


    fp=fopen(nombreArchivo, "r");
    if (fp == NULL){
        exit(0);
    }

    while ((read = getline(&line, &len, fp)) != -1) {

        pch = strtok (line," ,");

        if (strcmp(pch,"addi") == 0 || strcmp(pch,"subi") == 0) {

            while (count < 4) {
                printf ("entrando a: %s\n",pch);
                switch(count) {
                    case 0 :
                        printf("1...\n");
                        instrucction = pch;
                        break;
                    case 1 :
                        printf("2...\n");
                        register_1 = pch;
                        break;
                    case 2 :
                        printf("3...\n");
                        register_2 = pch;
                        break;
                    case 3 :
                        printf("4...\n");
                        number = pch;
                        break;
                }
                pch = strtok (NULL, " ,\n");
                addMoveR(plays,instrucction,register_1,register_2,number);
                count++;
            }

        } else if(strcmp(pch,"sw") == 0) {

            while (count < 3) {

                printf ("entrando a: %s\n",pch);
                switch(count) {
                    case 0 :
                        printf("1...\n");
                        instrucction = pch;
                        break;
                    case 1 :
                        printf("2...\n");
                        register_1 = pch;
                        break;
                    case 2 :
                        printf("3...\n");
                        number = pch;
                        break;
                }
                pch = strtok (NULL, " ,\n");
                addMoveI(plays,instrucction,register_1,number);
                count++;
            }
        }
        count = 0;


    }
    fclose(fp);

    if (line){
        free(line);
    }
    return;
}
