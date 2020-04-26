#include <zconf.h>
#include "catalog_tree.h"


int main() {
// FIRST & THIRD //
    char *path = "C:\\TEST"; // subtree -- root
    char *file_name = "fileA.txt";  // search in subtree
    long limit_size = 1300;    // огранчение по размеру

    node *root = make_node(path);
    tree *tree = make_tree(root);

    //////////////////////
    int count = 0;
    int *ptrCount = &count;
    /////
    int count_files = 0;
    int *ptrCountFiles = &count_files;
    /////
    int count_files2 = 0;    // для 3го задания
    int *ptrCountFiles2 = &count_files2;
    /////
    fill_in_tree(tree, path, root, ptrCount, file_name, ptrCountFiles, limit_size, ptrCountFiles2); // заполняю дерево
    ///////////////
    print_queue(count_files); // вывожу пути для первого задания


    // SECOND //
    ////////////////////////////
    int amount_arr[PATH_MAX] = {0};      // массив для хранения кол-ва файлов на разных уровнях
    int c_am = 0;
    int *ptr_cAm = &c_am;
    ////
    node *subtree = tree->first;
    second_task(subtree, 0, amount_arr, ptr_cAm);
    ////////////////////////////
    sortWeight(amount_arr, 0, c_am - 1);
    print_second_task(amount_arr, c_am);

    // THIRD PRINT //


    print_third_task(count_files2);
}