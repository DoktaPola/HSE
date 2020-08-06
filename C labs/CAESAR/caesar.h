#pragma once
#ifndef CAESAR_CAESAR_H
#define CAESAR_CAESAR_H

extern const char alph[];
extern const int len;

void encode_caesar_cipher(char* ch, char *arr, int shift, int *count, int mod);
void decode_caesar_cipher(char* ch, char *arr, int shift, int *count, int mod);
#endif //CAESAR_CAESAR_H
