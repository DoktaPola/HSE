#include <stdio.h>
#include <malloc.h>
#include "dict.h"

int main() {
    DICT *new_dict = make_dict();

    char* str[] = {"name", "age", "salary"};

    for (int i = 0; i < 3; ++i) {// заполняю ключи
        new_dict->keys[i].keys = str[i];
        new_dict->actual_size++; // сколько пар заполнено
    }

    int counter = 0;
    int *ptrCounter = &counter;
    new_dict->values[counter].bytes = "Ivan";// заполняю значения
    new_dict->types[counter++].type = T_char;

    new_dict->values[counter].num = 20;
    new_dict->types[counter++].type = T_inreger;

    new_dict->values[counter].d_num = 125.5;
    new_dict->types[counter++].type = T_double;

    get(new_dict, "name", ptrCounter);  // что лежить по СУЩ ключу
    get(new_dict, "weight", ptrCounter); // что лежит по НЕСУЩ ключу

    VALUE* n_value = (VALUE *) calloc(1, sizeof(VALUE));
    n_value->d_num = 70.5;
    int tp = T_double;
    put(new_dict, "weight", n_value, ptrCounter, tp); // добавляю новую пару

    VALUE* ne_value = (VALUE *) calloc(1, sizeof(VALUE));
    ne_value->bytes = "has";
    int typ = T_char;
    put(new_dict, "pet", ne_value, ptrCounter, typ);  // добавляю новую пару

    VALUE* new_value = (VALUE *) calloc(1, sizeof(VALUE));
    new_value->num = 185;
    int type = T_inreger;
    put(new_dict, "height", new_value, ptrCounter, type); // добавляю новую пару

    print(new_dict, ptrCounter); // вывести словарь

}
