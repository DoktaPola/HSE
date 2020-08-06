#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


char *read_data(char *input_file) {
    FILE *fptr;
    char ch;
    fptr = fopen(input_file, "r");
    if (fptr == NULL) {
        printf("Cannot open file \n");
        exit(-1);
    }
    ////////////
    char *buff = 0;
    int s = 100;
    buff = (char *) calloc(s, sizeof(char));
    //////////////////////
    int size = 0;
    int cnt = 0;

    ch = fgetc(fptr);
    while (ch != EOF) {
        if (ch == '\n') {
            buff[cnt] = '*';
            cnt++;
        } else {
            buff[cnt] = ch;
            cnt++;
        }
        size++;
        ch = fgetc(fptr);

    }

    fclose(fptr);
//    free(buff); // как это сделать и где?
    return buff;
}


void write_data(char *output_file, char *data, int file_size) {
    FILE *fp;
    int i;
    fp = fopen(output_file, "w");
    for (i = 0; i < file_size; i++) {
        if (data[i] == '*') {
            fprintf(fp, "%c", '\n');
        } else {
            fprintf(fp, "%c", data[i]);
        }
    }
    fclose(fp);
}

int get_file_size(char *input_file) {   // fix
    FILE *f = fopen(input_file, "r");
    fseek(f, 0L, SEEK_END);
    int f_size = ftell(f) + 1;
    fseek(f, 0L, SEEK_SET);
    fclose(f);
    return f_size;
}
