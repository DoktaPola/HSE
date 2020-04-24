#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <limits.h>
#include <sys/stat.h>
#include "catalog_tree.h"
#include "queue.h"
#include "queue_2.h"

node *make_node(char *data) {
    node *root = (node *) malloc(sizeof(node));
    root->data = data;
    root->first_sibling = NULL;
    root->first_child = NULL;

    char *slash_r = strchr(data, '/');  // проверка на тип
    char *slash_l = strchr(data, '\\');
    if (slash_r || slash_l) {
        root->type = folder;
    } else {
        root->type = file;
    }
    return root;
}

tree *make_tree(node *root) {
    tree *my_tree = (tree *) malloc(sizeof(tree));
    my_tree->first = root;
    return my_tree;
}

void first_task(char *full_name, char *name, char *tofind_file, int *count_files) {
    if (strcmp(name, tofind_file) == 0) { // ести это искомый файл, кладем в очередь
        char *data = (char *) calloc(100, sizeof(char));  // put in queue
        strcpy(data, full_name);
        queue_push(data);
        (*count_files)++;
    }
}

void third_task(long limit_size, char *full_name, int *count_files2){
    long nFileLen = 0;
    struct _stat st;
    int res = _stat(full_name, &st);
    if (res == 0)
        nFileLen = st.st_size;

    if (nFileLen > limit_size){
        char *name = (char *) calloc(100, sizeof(char));  // put in queue
        strcpy(name, full_name);
        push(name);
        (*count_files2)++;
    }
}

node *add_brother(node *old_brother, char *name, char *full_name, char *tofind_file, int *count_files,  long limit_size, int *count_files2) {
    node *p = old_brother;
    while (p && p->first_sibling) {
        p = p->first_sibling;
    }
    node *temp;
    temp = (node *) malloc(sizeof(node));
    temp->data = (char *) malloc(strlen(name) + 1);
    strcpy(temp->data, name);
    temp->first_sibling = NULL;
    temp->first_child = NULL;
    temp->prev = old_brother;
    char *point = strchr(name, '.');  // проверка на тип
    if (point) {
        temp->type = file;

        third_task(limit_size, full_name, count_files2); // ТРЕТЬЕ ЗАДАНИЕ
        first_task(full_name, name, tofind_file, count_files);//ПЕРВОЕ ЗАДАНИЕ
    } else {
        temp->type = folder;
    }

    if (p) {
        p->first_sibling = temp;
    } else {
        p = temp;
    }
    return old_brother;
}

node *add_child(node *root, char *name, char *full_name, char *tofind_file, int *count_files,  long limit_size, int *count_files2) {
    if (root->first_child)
        root->first_child = add_brother(root->first_child, name, full_name, tofind_file, count_files, limit_size, count_files2);
    else {
        root->first_child = (node *) malloc(sizeof(node));
        root->first_child->data = (char *) malloc(strlen(name) + 1);
        strcpy(root->first_child->data, name);
        root->first_child->first_child = NULL;
        root->first_child->first_sibling = NULL;
        root->first_child->prev = root;

        char *point = strchr(name, '.');  // проверка на тип
        if (point) {
            root->first_child->type = file;

            third_task(limit_size, full_name, count_files2); // ТРЕТЬЕ ЗАДАНИЕ
            first_task(full_name, name, tofind_file, count_files);//ПЕРВОЕ ЗАДАНИЕ
        } else {
            root->first_child->type = folder;
        }
    }
    return root;
}

node *fill_in_tree(tree *tree, char *path, node *root, int *count, char *tofind_file, int *count_files,  long limit_size, int *count_files2) {
    struct dirent *direntp = NULL;
    DIR *dirp = NULL;
    size_t path_len;

    /* Check input parameters. */
    if (!path)
        return -1;
    path_len = strlen(path);

    if (!path || !path_len || (path_len > PATH_MAX))
        return -1;

    /* Open directory */
    dirp = opendir(path);
    if (dirp == NULL) {
        return -1;
    }

    while ((direntp = readdir(dirp)) != NULL) {

        char full_name[PATH_MAX + 1];

        /* Ignore special directories. */
        if ((strcmp(direntp->d_name, ".") == 0) ||
            (strcmp(direntp->d_name, "..") == 0))
            continue;

        /* Calculate full name, check we are in file length limts */
        if ((path_len + strlen(direntp->d_name) + 1) > PATH_MAX)
            continue;

        strcpy(full_name, path);  // положила root
        if (full_name[path_len - 1] != '/')
            strcat(full_name, "\\");
        strcat(full_name, direntp->d_name); // кладу подкаталог

        root = add_child(root, (char *) direntp->d_name, full_name, tofind_file, count_files, limit_size, count_files2); // ДОБАВЛЯЮ РЕБЕНКА
        ////////////////////////////
        node *p = root->first_child;
        while (p->first_sibling)
            p = p->first_sibling;
        p = fill_in_tree(tree, full_name, p, count, tofind_file, count_files, limit_size,count_files2);
        ////////////////////////////
    }
    /* Finalize resources. */
    (void) closedir(dirp);
    return root;
}

void print_queue(int count_files) {
    printf("TASK 1st: \n\n");
    for (int i = 0; i < count_files; ++i) {
        printf("%s\n", queue_pop());
    }
    printf("\n");
}


void second_task(node *tree, int level, int *amount_arr, int *cAm) { // level = 0
    char *path_name = (char *) calloc(100, sizeof(char)); // память под строчку
    node *p = tree;

    if (p->type == folder) {
        strcpy(path_name, p->data);
    } else {
        amount_arr[*cAm] = level; // какой уровень дерева
        (*cAm)++;
    }
    if (p->first_child)
        second_task(p->first_child, level + 1,  amount_arr, cAm);
    if (p->first_sibling)
        second_task(p->first_sibling, level, amount_arr, cAm);
}


void sortWeight(int *arr, int left, int right) { // сортирую кол-во файлов на разных уровнях
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

void  print_second_task(const int *amount_arr, int cAm){
    printf("TASK 2nd: \n\n");
    int count = 1;
    int j = 1;
    for (int i = 0; i < cAm; ++i) {
        int data = amount_arr[i];
        while (amount_arr[j] == data){
            j++;
            count++;
        }
        if (amount_arr[i] == 0) {
            printf("In subtree root:");
        }
        for (int k = 0; k < amount_arr[i]; ++k) {
            printf("../");
        }
        printf(" ");
        if (count == 1){
            printf("%d file on this level.\n", count);
        } else{
            printf("%d files on this level.\n", count);
        }
        count = 0;
        i = j-1;
    }
    printf("TOTAL AMOUNT of files in the specified subtree: %d\n\n", cAm);
}

void print_queue2(int count_files) {
    printf("TASK 3d: \n\n");
    for (int i = 0; i < count_files; ++i) {
        printf("%s\n", pop());
    }
    printf("\n");
}