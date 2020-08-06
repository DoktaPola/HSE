#include "caesar.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

const char alph[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                     'J','K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c',
                     'd','e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
                     'x','y', 'z', ' '};
const int len = sizeof(alph);

void encode_caesar_cipher(char *ch, char *arr, int shift, int *count, int mod) {
    char new_ch;
    for (int i = 0; i < len; ++i) {
        if (*ch == alph[i]) {
            int ind = 0;
            if (mod == 0){
                ind = (i + (shift % len)) % len;
            }else if (mod == 1){
                ind = (i - (shift%len)) % len;
            }
            new_ch = alph[ind];
            arr[*count] = new_ch;
            (*count)++;
        } else if (*ch == '*') {
            arr[*count] = '*';
            (*count)++;
            break;
        }
    }
}

void decode_caesar_cipher(char *ch, char *arr, int shift, int *count, int mod) {
    encode_caesar_cipher(ch, arr, shift, count, mod);
}