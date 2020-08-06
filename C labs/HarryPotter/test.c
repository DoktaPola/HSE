#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

void word_counter(char *arr, char *person, int *count) {
    char *res = 0; // хранит адрес первого вхождения искомого слова
    int person_len = strlen(person);
    res = strstr(arr, person);
    if (res) {
        (*count)++;
        for (int i = 0; i < res - arr + 1 + person_len - 1; ++i) {
            arr[i] = ' ';
        }
        word_counter(arr, person, count);
    }
}

void make_sent(char *my_str, char *person, int *count, char *arr) {
    int cnt = 0;
    char *ptr = my_str; //  перевод в нижний регистр
    while (*ptr) {
        if ((*ptr == '!') || (*ptr == '?')) {
            *ptr = '.';
        }
        *ptr = (char) tolower(*ptr);
        ++ptr;
    }
    char new_sent[1000000] = {0};
    char delim[] = " \t\n\\/,-";
    char *p = strtok(my_str, delim);
    while (p != NULL) {
        strcat(new_sent, p);

        p = strtok(NULL, delim);
    }
    int len = strlen(new_sent);
    for (int i = 0; i < len - 1; ++i) {  // -1
        if (new_sent[i] == '.') {  //считываю до точки одно предложение
            word_counter(arr, person, count);  // вызываем подсчет слов
            memset(arr, 0, sizeof(arr));// очищаю массив
            cnt = 0;
        } else {
                arr[cnt] = new_sent[i];
                cnt++;
        }
    }
}

int main(void) {

    char human[50];  // искомый персонаж
    gets(human);
    int c = 0;

    char *person = 0;
    int size = 100;
    person = (char *) calloc(size, sizeof(char));

    //  перевод в нижний регистр
    for (int i = 0; human[i] != '\0'; i++) {
        char re = (char) tolower(human[i]);
        if (human[i] != ' ') {
            person[c] = re;
            c++;
        }
    }

    int count = 0;
    int *ptrCount = &count;

    FILE *mf;
    long lSize;
    char *buffer;
    size_t result;

    mf = fopen("Book 1 - The Philosopher's Stone.txt", "r");
    // Проверка открытия файла
    if (mf == NULL) {
        printf("Error\n");
        return -1;
    }

    // obtain file size:
    fseek(mf, 0, SEEK_END);
    lSize = ftell(mf);
    rewind(mf);

    // allocate memory to contain the whole file:
    buffer = (char *) malloc(sizeof(char) * lSize);
    if (buffer == NULL) {
        fputs("Memory error", stderr);
        exit(1);
    }

    // copy the file into the buffer:
    result = fread(buffer, 1, lSize, mf);
    if (result != lSize) {
        fputs("Reading error", stderr);
        exit(2);
    }

    /* the whole file is now loaded in the memory buffer. */
    char *arr = 0;
    int n = 100000;
    arr = (char *) calloc(n, sizeof(char));

    make_sent(buffer, person, ptrCount, arr);

    FILE *fp;
    fp = fopen("rez_HP.txt", "w");
    fprintf(fp, "%s:\t", human );
    fprintf(fp, "%d", count);

    // terminate
    fclose(fp);
    fclose(mf);
    free(person);
    free(arr);
    free(buffer);
    return 0;
}