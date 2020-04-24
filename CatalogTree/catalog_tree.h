#ifndef CATALOGTREE_CATALOG_TREE_H
#define CATALOGTREE_CATALOG_TREE_H

#include "queue.h"

typedef enum Type {
    folder,
    file
} TYPE;

typedef struct Node {
    char *data;
    struct Node *first_sibling;
    struct Node *first_child;
    struct Node *prev;
    TYPE type;
} node;

typedef struct Tree {
    node *first;   // pointer on root
} tree;

node *make_node(char *data);

tree *make_tree(node *root);

node *
fill_in_tree(tree *tree, char *path, node *root, int *count, char *tofind_file, int *ptrCountFiles, long limit_size,
             int *count_files2);

void print_queue(int count_files);

void sortWeight(int *arr, int left, int right);//////////////
void second_task(node *tree, int level, int *amount_arr, int *cAm);

void print_second_task(const int *amount_arr, int cAm);

void print_queue2(int count_files);

#endif //CATALOGTREE_CATALOG_TREE_H
