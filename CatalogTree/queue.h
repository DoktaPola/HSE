#ifndef CATALOGTREE_QUEUE_H
#define CATALOGTREE_QUEUE_H

typedef struct Q_dt{
    char* info;
}q_dt;

void queue_push(char* l_item);
char* queue_pop();

#endif //CATALOGTREE_QUEUE_H
