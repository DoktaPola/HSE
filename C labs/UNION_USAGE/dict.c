#include <stdio.h>
#include <malloc.h>
#include "dict.h"

#define  SIZE 15

DICT *make_dict() {
    DICT *new_dict = (DICT *) calloc(SIZE, sizeof(DICT));  // создаю словарь
    new_dict->values = (VALUE *) calloc(SIZE, sizeof(VALUE)); //  память под значения в словаре
    new_dict->keys = (KEY *) calloc(SIZE, sizeof(KEY));
    new_dict->types = (TS *) calloc(SIZE, sizeof(TS));
    for (int i = 0; i < SIZE; ++i) {
        new_dict->values[i].bytes = (char *) calloc(SIZE, sizeof(char)); // память под 15 значений в каждом VALUE
        new_dict->keys[i].keys = (char *) calloc(SIZE, sizeof(char)); // под 15 ключей
        new_dict->types[i].type = (int) calloc(SIZE, sizeof(int));
    }

    new_dict->actual_size = 0;
    new_dict->max_size = SIZE;
    return new_dict;
}

void get(DICT *my_dict, char *key, int *counter) {
    char *ch = {0};
    for (int i = 0; i < (*counter); ++i) {
        ch = my_dict->keys[i].keys;
        if (ch == key) {
            if (my_dict->types[i].type == T_char) {
                printf("%s\n", my_dict->values[i].bytes);
                break;
            } else if (my_dict->types[i].type == T_inreger) {
                printf("%d\n", my_dict->values[i].num);
                break;
            } else if (my_dict->types[i].type == T_double) {
                printf("%f\n", my_dict->values[i].d_num);
                break;
            }
        }
    }
    if (ch != key){
        printf("Such key doesn't exist!\n");
    }
    printf("\n");
}

void put(DICT *my_dict, char *key, VALUE *new_value, int *counter, int type) {  // отслеживать max size
    for (int i = 0; i < (*counter); ++i) {
        char *ch = my_dict->keys[i].keys;
        if (ch == key) { // если ключ уже существует, заменяем value
            if (type == T_char) {
                my_dict->values[i].bytes = new_value->bytes;////
            } else if (type == T_inreger) {
                my_dict->values[i].num = new_value->num;////
            } else if (type == T_double) {
                my_dict->values[i].d_num = new_value->d_num;////
            }
        }
    }
    // если ключа еще нет
    if (my_dict->actual_size != (my_dict->max_size / 2)) { // пока не дошли до половины MAX SIZE
        my_dict->keys[(*counter)].keys = key; // положила новый ключ

        if (type == T_char) {
            my_dict->values[*counter].bytes = new_value->bytes;
            my_dict->types[(*counter)++].type = T_char;
            my_dict->actual_size++;                          // словарь вырос
        } else if (type == T_inreger) {
            my_dict->values[*counter].num = new_value->num;
            my_dict->types[(*counter)++].type = T_inreger;
            my_dict->actual_size++;                         // словарь вырос
        } else if (type == T_double) {
            my_dict->values[*counter].d_num = new_value->d_num;
            my_dict->types[(*counter)++].type = T_double;
            my_dict->actual_size++;                         // словарь вырос
        }
    } else {

        my_dict = (DICT *) realloc(my_dict, SIZE * 2);
    }
}

void print(DICT *full_dict, int *counter) {
    for (int i = 0; i < (*counter); ++i) {
        printf("%d", i + 1);
        printf(" pair: ");

        printf("%s\t", full_dict->keys[i].keys); // вывела ключ

        if (full_dict->types[i].type == T_char) {
            printf("%s\n", full_dict->values[i].bytes);
        } else if (full_dict->types[i].type == T_inreger) {
            printf("%d\n", full_dict->values[i].num);
        } else if (full_dict->types[i].type == T_double) {
            printf("%0.2f\n", full_dict->values[i].d_num);
        }
        printf("\n");
    }
}


