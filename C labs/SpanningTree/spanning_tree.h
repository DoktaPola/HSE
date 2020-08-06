#ifndef SPANNINGTREE_SPANNING_TREE_H
#define SPANNINGTREE_SPANNING_TREE_H

#define MAX 5

struct Graph {
    int n;
    int G[MAX][MAX];
};

struct Graph *createGraph(int n, int G[][MAX]);

void printGraph(struct Graph *graph);

void collectWeights(struct Graph *graph, int *arr, int n, int *count);

void sortWeight(int *arr, int left, int right);

void changeColour(int i, int j, int *count_colour, int *colour, int *count_finale, int *finale);

int findSpanningTree(struct Graph *graph, const int *arr, const int *count_weight, int n,  int *finale, int *arr_weight, int* weight);

void printSpanningTree(int *finale, int *arr_weight, const int size_finale, const int *weight);

#endif //SPANNINGTREE_SPANNING_TREE_H
