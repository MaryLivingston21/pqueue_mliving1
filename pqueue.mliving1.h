//
// Created by Mary Livingston on 2020-09-22.
//

#ifndef PQUEUE_MLIVING1_PQUEUE_MLIVING1_H
#define PQUEUE_MLIVING1_PQUEUE_MLIVING1_H

#define MAX_NAME_LENGTH 64
typedef struct {
    char title[MAX_NAME_LENGTH]; char artist[MAX_NAME_LENGTH];
} Song;

typedef struct PQueueStruct {
    int priority;
    void *data;
    struct PQueueStruct *next;
} PQueueNode;

// Puts data in the priority queue in the correct place.
// If there is already 1+ nodes in the list having the same priority,
// puts the new node after all nodes with same priority.
// Returns 0
int enqueue(PQueueNode **pqueue, int priority, void *data);

// Removes the front of the list
// Free the queue node itself in your function (but not the data!).
// Return the data from that list node
// Returns NULL if the pqueue is empty
void *dequeue(PQueueNode **pqueue);

//Returns the data from the first node in the pqueue
// Returns NULL if the pqueue is empty
void *peek(PQueueNode *pqueue);

//Prints the data from each node in the queue.
void printQueue(PQueueNode *pqueue, void (printFunction)(void*));

//Returns the priority of the first node in the pqueue.
// Returns -1 if the pqueue is empty
int getMinPriority(PQueueNode *pqueue);

// Returns the number of nodes in the pqueue.
int queueLength(PQueueNode *pqueue);

//Prints an instance of Song as "%s" (%s), with the title field and name field.
// Assume that a pointer to Song is passed in to this function.
// You’ll have to cast the /tt data parameter to a Song in order to get to the title and artist fields.
void printSong(void *data);

#endif //PQUEUE_MLIVING1_PQUEUE_MLIVING1_H
