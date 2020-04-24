#include <malloc.h>
#include <zconf.h>
#include "queue_2.h"

dt queue2[PATH_MAX + 1];   // pointer on root

dt* head = &queue2[0];
dt* tail = &queue2[0];

void push(char* l_item){
    dt* node =  (dt *) malloc(sizeof(dt));
    node->data = l_item;

    if(head != queue2 + sizeof(queue2)/sizeof(*queue2)){  //if queue is not full, do the job
//         Push all elements one step further
        dt* traveler = head;
        for(; traveler != tail; --traveler){
            *traveler = *(traveler - 1);
        }
        ++head;
        *tail = *node;
    }
}

char* pop(){
    dt temp;
    if (head == tail) return "\0"; // the queue is empty
    --head;
    temp = *head;

    dt* n = (dt *) malloc(sizeof(dt));
    n->data = "\0";
    *head = *n;
    return temp.data;
}
