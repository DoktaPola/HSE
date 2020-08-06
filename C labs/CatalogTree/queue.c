#include <malloc.h>
#include <zconf.h>
#include "queue.h"

q_dt queue[PATH_MAX + 1];   // pointer on root

q_dt* queue_head = &queue[0];
q_dt* queue_tail = &queue[0];


void queue_push(char* l_item){
    q_dt* node =  (q_dt *) malloc(sizeof(q_dt));
    node->info = l_item;

    if(queue_head != queue + sizeof(queue)/sizeof(*queue)){  //if queue is not full, do the job
//         Push all elements one step further
        q_dt* traveler = queue_head;
        for(; traveler != queue_tail; --traveler){
            *traveler = *(traveler - 1);
        }
        ++queue_head;
        *queue_tail = *node;
    }
}

char* queue_pop(){
    q_dt temp;
    if (queue_head == queue_tail) return "\0"; // the queue is empty
    --queue_head;
    temp = *queue_head;

    q_dt* n = (q_dt *) malloc(sizeof(q_dt));
    n->info = "\0";
    *queue_head = *n;
    return temp.info;
}
