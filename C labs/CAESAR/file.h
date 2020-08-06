#pragma once
#ifndef CAESAR_FILE_H
#define CAESAR_FILE_H
#include <stdio.h>

char* read_data(char* input_file);
void write_data(char* output_file, char* data, int file_size);
int get_file_size(char* input_file);

#endif //CAESAR_FILE_H
