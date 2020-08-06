#include <stdio.h>
#include "spanning_tree.h"

int main() {
    int row_size = 5;
    int column_size = 5;
    int i, j, n;
    int G[row_size][column_size];
    int arr[row_size + column_size];
    int count_weight = 0;
    int *ptrCount_weigh = &count_weight;

    printf("\nEnter number of vertices:");

    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    struct Graph *graph = createGraph(n, G);

    printGraph(graph);

    collectWeights(graph, arr, n, ptrCount_weigh);

    sortWeight(arr, 0, row_size);
//    for (int k = 0; k < count_weight; ++k) {
//        printf("Sorted: %d\t", arr[k]);
//    }
//    printf("\n");


    int arr_weight[20];
    int finale[20] = {-1};
    int weight = 0;
    int *ptrWeight = &weight;
    int size_finale = findSpanningTree(graph, arr, ptrCount_weigh, n, finale, arr_weight, ptrWeight);

    printSpanningTree(finale, arr_weight, size_finale, ptrWeight);


}