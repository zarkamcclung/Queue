/*Zarka Srabony
CS-2413-001
Assignment 3
This program will read command from user and perform funtions like enqueue, dequeue, display on the queue*/

#include "stdheader.h"
#include "queue.h"

int main(int argc, char **argv){
    //initialize new stack
    queue_ptr q = createQueue();
    
    //read in stack comman
    char input[256];
    int num1, num2, i;
    
    //read commands
    while (scanf("%s", input) != EOF) {
        
        if ( strcmp(input, "enqueue")==0 ){ // enqueue an integer to integer
            scanf("%d", &num1); //read the starting integer
            scanf("%d", &num2); //read the end integer
            
            for (i=num1; i<=num2; i++){
                enqueue (q, i);
                printf ("Enqueued %d\n", i);
            }
            
        }else if ( strcmp(input, "dequeue")==0 ){
            scanf("%d", &num1); //read the integer
            
            for(i=0; i<num1; i++){
                if ( isEmpty(q) ){
                    printf("Queue Is Empty\n");
                }else{
                    printf ("Dequeued %d\n", dequeue(q));
                }
            }
            
        
        }else{
            if (strcmp(input, "peek")==0){
                if ( isEmpty(q) ){
                    printf("Queue Is Empty\n");
                }else{
                    printf("Peaked %d\n", peek(q));
                }
                
            }else if (strcmp(input, "display")==0){
                if ( isEmpty(q) ){
                    printf("Queue Is Empty\n");
                }else{
                    display(q);
                }
            }
            
            
        }
        
        
    }
    
    //delete the stack
    destroyQueue(q);
    
    
    
    return 0;
}

