//rui zhang
//cs 2413-001
//assignment2

#include "stdheader.h"
#include "queue.h"


//new Queue
queue_ptr createQueue(){
    queue_ptr q = (queue_ptr) malloc(sizeof(queue));
    q->head = NULL;
    q->back = NULL;
    
    return q;
}

//destroy Queue
void destroyQueue(queue_ptr q){
    DLLNode_ptr temp;
    
    while (q->head != NULL ){
        temp = q->head->next;
        free(q->head);
        q->head = temp;
    }
    free(q);
    
}

//is empty
int isEmpty(queue_ptr q){

    return (q->head == NULL) && (q->back == NULL);
    
}

//dequeue
element dequeue(queue_ptr q){
    
    element e = q->head->e;
    
    if (q->head->next == NULL){
        free(q->head);
        q->head = NULL;
        q->back = NULL;
        
    }else{
        q->head = q->head->next;
    
        free(q->head->prev);
        q->head->prev = NULL;
    }
    
    return e;
    
}

//enqueue
void enqueue(queue_ptr q, element ele){
    DLLNode_ptr n  = (DLLNode_ptr) malloc(sizeof(DLLNode));
    
    n->e = ele;
    n->prev = NULL;
    n->next = NULL;
    
    if (q->back == NULL){
        q->back = q->head = n;
        
    }else{
        q->back->next = n;
        
        n->prev = q->back;
        q->back = n;
        
    }
    

    
}

//peak
element peek(queue_ptr q){
    return q->head->e;
    
}


//show
void display(queue_ptr q){
    printf("Display In Reverse\n");
    DLLNode_ptr temp = q->back;
    
    while (temp != NULL ){
        printf("%d\n", temp->e);
        temp = temp->prev;
    }
    
    
    
}