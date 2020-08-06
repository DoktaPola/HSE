#ifndef UNION_USAGE_DICT_H
#define UNION_USAGE_DICT_H

typedef enum Type{
    T_inreger,
    T_double,
    T_char
}TYPE;

typedef struct Type_storage{
    int type;
}TS;

typedef union Value{
    int num;
    char *bytes;
    double d_num;
} VALUE;

typedef struct Key{
    char* keys;
}KEY;

typedef struct Dict{
    VALUE* values;
    KEY* keys;
    TS* types;
    int actual_size;
    int max_size;
}DICT;

DICT* make_dict();
void get(DICT* my_dict, char* key, int *counter);
void put(DICT* my_dict, char* key, VALUE* new_value, int *counter, int type);
void print(DICT* full_dict, int *counter);

#endif //UNION_USAGE_DICT_H
