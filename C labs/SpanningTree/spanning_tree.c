#include <stdio.h>
#include "spanning_tree.h"
#include <malloc.h>

#define MAX 5

struct Graph *createGraph(int n, int G[][MAX]) {
    struct Graph *graph =
            (struct Graph *) malloc(sizeof(struct Graph));
    graph->n = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num = G[i][j];
            graph->G[i][j] = num;
        }
    }
    return graph;
}

void printGraph(struct Graph *graph){
    printf("Initial graph: \n");
    for (int i = 0; i < graph->n; i++) {
        for (int j = 0; j < graph->n; j++) {
            printf("%d\t", graph->G[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void collectWeights(struct Graph *graph, int *arr, int n, int *count) {  // собираю веса половины графа
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (graph->G[i][j] != 0) {
                arr[*count] = graph->G[i][j];
                (*count)++;
            }
        }
    }
}


void sortWeight(int *arr, int left, int right) { // сортирую
    int pivot; // разрешающий элемент
    int l_hold = left; //левая граница
    int r_hold = right; // правая граница
    pivot = arr[left];
    while (left < right) // пока границы не сомкнутся
    {
        while ((arr[right] >= pivot) && (left < right))
            right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
        if (left != right) // если границы не сомкнулись
        {
            arr[left] = arr[right]; // перемещаем элемент [right] на место разрешающего
            left++; // сдвигаем левую границу вправо
        }
        while ((arr[left] <= pivot) && (left < right))
            left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
        if (left != right) // если границы не сомкнулись
        {
            arr[right] = arr[left]; // перемещаем элемент [left] на место [right]
            right--; // сдвигаем правую границу вправо
        }
    }
    arr[left] = pivot; // ставим разрешающий элемент на место
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
        sortWeight(arr, left, pivot - 1);
    if (right > pivot)
        sortWeight(arr, pivot + 1, right);
}

void changeColour(int i, int j, int *count_colour, int *colour, int *count_finale, int *finale) {
    colour[i] = *count_colour;  //  смена цвета
    colour[j] = *count_colour;
    (*count_colour)++;

    finale[*count_finale] = i;
    (*count_finale)++;
    finale[*count_finale] = j;
    (*count_finale)++;
}


int findSpanningTree(struct Graph *graph, const int *arr, const int *count_weight, int n, int *finale, int *arr_weight, int *weight) {
    int w_count = 0;
    int count_colour = 1;
    int *ptrCount_colour = &count_colour;
    int colour[20];
    for (int l = 0; l < 20; ++l) {
        colour[l] = -1;
    }
    int count_finale = 0;
    int *ptrCount_finale = &count_finale;

    for (int w = 0; w < (*count_weight); ++w) { // иду по весам
        for (int i = 1; i < n; i++) {  //иду по половинке графа
            for (int j = 0; j < i; j++) {
                if (graph->G[i][j] == arr[w]) { // нахожу 2 вершины с таким весом
                    if (finale[0] == -1) { //  кладу первую пару
                        arr_weight[w_count++] = arr[w];//////////////////////
                        (*weight) += arr[w]; // считаю вес
                        changeColour(i, j, ptrCount_colour, colour, ptrCount_finale, finale);
                    } else {
                        if (colour[i] != colour[j]) {  // если цвета не равны
                            int col_i = colour[i];
                            int col_j = colour[j];
                            for (int k = 0; k < n; ++k) {  // меняю у эл-в которые буду соединять цвет на общий
                                if (colour[i] != -1) {
                                    if (colour[k] == col_i) {
                                        colour[k] = count_colour;
                                    }
                                }
                                if (colour[j] != -1) {
                                    if (colour[k] == col_j) {
                                        colour[k] = count_colour;
                                    }
                                }
                            }
                            (*weight) += arr[w]; // считаю вес
                            arr_weight[w_count++] = arr[w];
                            changeColour(i, j, ptrCount_colour, colour, ptrCount_finale, finale);
                        }
                    }
                }
            }
        }
    }
    return count_finale;
}

void printSpanningTree(int *finale, int *arr_weight, const int size_finale, const int *weight){
    printf("Edges of Spanning Tree: ");
    int c = 0;
    int c_w =0;
    for (int i = 0; i < size_finale; ++i) {
        printf("%d", finale[i]);
        if (c == 1){
            printf("(%d)",arr_weight[c_w]);
            c_w++;
            printf("%c\t", ';');
        } else if (c == 2 || c == 0){
            printf(" -> ");
            c = 0;
        }
        c++;
    }
    printf("\nWeight: %d", *weight);
}