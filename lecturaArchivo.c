#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void leerArchivo(char * nombreArchivo){
    FILE *fp;
    char *line = NULL;

    size_t len = 0;
    ssize_t read;

    fp=fopen(nombreArchivo, "r");
    if (fp == NULL){
        exit(0);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("%s", line);
    }
    fclose(fp);

    if (line){
        free(line);
    }
    return;
}
