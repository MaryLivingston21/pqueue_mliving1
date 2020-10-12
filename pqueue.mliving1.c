#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "pqueue.mliving1.h"

int enqueue(PQueueNode **pqueue, int priority, void *data){
    PQueueNode *newNode;
    newNode = (PQueueNode *) malloc(sizeof(PQueueNode));
    newNode->priority = priority;
    newNode->data = data;

    //printf("Adding node to queue: ");
    //printSong(newNode->data);
    //printf(" \n");

    //if queue is empty
    if (*pqueue == NULL) {
        newNode->next = NULL;
        *pqueue = newNode;
    } else {
        // if only one node in queue
        if ((*pqueue)->next == NULL){
            // if new node has bigger priority, add to end of queue
            if ((*pqueue)->priority <= newNode->priority){
                (*pqueue)->next = newNode;
                newNode->next = NULL;
            } else {
                //have new node point to beginning of queue
                newNode->next = *pqueue;
                //set head node in queue to new node
                *pqueue = newNode;
            }
        } else {
            //get head node in queue
            PQueueNode *i = *pqueue;
            // if head needs to be reset
            if (i->priority > newNode->priority){
                newNode->next = i;
                * pqueue = newNode;
            } else {
                // while there exists next node thats priority is less than or equal, increment
                while (i->next != NULL && i->next->priority <= newNode->priority) {
                    i = i->next;
                }
                newNode->next = i->next;
                i->next = newNode;
            }
        }
    }

    //printf("Print queue after new node added: \n");
    //printQueue(*pqueue, printSong);
    //printf("\n");

    return 0;
}

void *dequeue(PQueueNode **pqueue){
    //if queue is empty
    if (*pqueue == NULL) {
        return NULL;
    } else {
        // get head node in the queue
        PQueueNode *poppedNode = *pqueue;
        //get head node's data
        void *poppedNodeData = poppedNode->data;
        //get the second node in the stack
        PQueueNode *newHead = (*pqueue)->next;
        // TODO: make sure this is right: free the queue node itself but not the data!
        free(poppedNode);
        // set the head node in the queue to Node 2
        *pqueue = newHead;
        // return popped node
        return poppedNodeData;
    }
}

void *peek(PQueueNode *pqueue){
    //if queue is empty
    if (pqueue==NULL) {
        return NULL;
    }else{
        return pqueue->data;
    }
}

//Prints the data from each node in the queue.
void printQueue(PQueueNode *pqueue, void (printFunction)(void*)){
    if (pqueue != NULL){
        //get first node in queue
        PQueueNode *i = pqueue;
        printf("priority = %d ", i->priority);
        printFunction(i->data);
        // while next node exists
        while (i->next != NULL){
            //increment node
            i = i->next;
            // print node
            printf("priority = %d ", i->priority);
            printFunction(i->data);
        }
    } else {
        printf("(queue is empty)\n");
    }
}

int getMinPriority(PQueueNode *pqueue){
    if (pqueue != NULL) {
        return pqueue->priority;
    } else {
        return -1;
    }
}

int queueLength(PQueueNode *pqueue){
    int numNodes = 0;
    //if queue isn't empty
    if (pqueue != NULL){
        //get first node in queue
        PQueueNode *i = pqueue;
        //increment number of nodes
        numNodes = numNodes + 1;
        // while next node exists
        while (i->next != NULL){
            //increment node
            i = i->next;
            //increment number of nodes
            numNodes = numNodes + 1;
        }
    }
    return numNodes;
}

void printSong(void *data){
    Song* thisSong = (Song*)data;
    printf("data = '%s' (%s) \n", thisSong->title, thisSong->artist);
}

//int main() {
//    printf("Hello, World!\n");
//    return 0;
//}