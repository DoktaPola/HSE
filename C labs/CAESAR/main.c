#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "file.h"
#include "caesar.h"


int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Wrong amount of input arguments"); //////////////
        return -1;
    }
    char *text = read_data(argv[2]);  // call read func

    /////////////
    char *arr = 0;
    int n = 100;
    arr = (char *) calloc(n, sizeof(char));
    ////////////

    int file_size = get_file_size(argv[2]);

    int shift = atoi(argv[4]);
    int count = 0;
    int *ptrCount = &count;
    int mod = atoi(argv[1]);

    if (mod == 0) {
        for (int i = 0; i < file_size; i++) {
            char ch = text[i];
            encode_caesar_cipher(&ch, arr, shift, ptrCount, mod);  // call C
        }
    } else if (mod == 1) {
        for (int i = 0; i < file_size; i++) {
            char ch = text[i];
            decode_caesar_cipher(&ch, arr, shift, ptrCount, mod);  // call C
        }
    }

    write_data(argv[3], arr, file_size);

    free(arr);
    return 0;

}