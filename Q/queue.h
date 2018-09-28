#ifndef ____DLinked_List_H____
#define ____DLinked_List_H____

#include "stdheader.h"

//Structures

//element is content of a node.
typedef int element;

//node is doulbe linked in a linked list.
struct _DLLNode{
    element e;
    struct _DLLNode* next;
    struct _DLLNode* prev;
};

typedef struct _DLLNode    DLLNode;
typedef struct _DLLNode*   DLLNode_ptr;

//linked list is a series of links tracked by the head and tail of the list.
struct _DLL{
    DLLNode_ptr head;
    DLLNode_ptr back;
};

typedef struct _DLL queue;
typedef struct _DLL* queue_ptr;


queue_ptr createQueue();
void destroyQueue(queue_ptr);
int isEmpty(queue_ptr);

void enqueue(queue_ptr, element);
element dequeue(queue_ptr);

element peek(queue_ptr);
void display(queue_ptr);


#endif

