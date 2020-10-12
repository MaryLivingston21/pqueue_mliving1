//
// Created by Mary Livingston on 2020-10-05.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pqueue.mliving1.h"

Song *createSong(char *title, char *artist) {
    Song *song;
    song = (Song *) malloc(sizeof(Song));
    strcpy(song->title, title);
    strcpy(song->artist, artist);
    return song;
}

void pqueueTests() {
    int minPriority;
    PQueueNode *pqueue = NULL;
    Song *song;

    song = createSong("Shape of You", "ED Sheeran");
    enqueue(&pqueue, 3, song);

    song = createSong("Humble", "Kendrick Lamar");
    enqueue(&pqueue, 8, song);

    song = createSong("Attention", "Charlie Puth");
    enqueue(&pqueue, 1, song);

    song = createSong("Passionfruit", "Drake");
    enqueue(&pqueue, 9, song);

    song = createSong("Thunder", "Imagine Dragons");
    enqueue(&pqueue, 2, song);

    song = createSong("Me Rehuso", "Danny Ocean");
    enqueue(&pqueue, 12, song);

    song = createSong("The Cure", "Lady Gaga");
    enqueue(&pqueue, 9, song);

    song = createSong("Location", "Khalid");
    enqueue(&pqueue, 2, song);

    song = createSong("I Feel It Coming", "The Weeknd");
    enqueue(&pqueue, 1, song);

    printQueue(pqueue, printSong);

    printf("--------------------------------------------------\n");
    song = peek(pqueue);
    printf("peek: ");
    printSong(song);

    song = dequeue(&pqueue);
    printf("dequeued: ");
    printSong(song);

    song = peek(pqueue);
    printf("peek: ");
    printSong(song);

    song = dequeue(&pqueue);
    printf("dequeued: ");
    printSong(song);

    song = peek(pqueue);
    printf("peek: ");
    printSong(song);

    printf("--------------------------------------------------\n");

    song = createSong("Life Changes", "Thomas Rhett");
    enqueue(&pqueue, 1, song);

    song = createSong("Whatcha Drinkin 'Bout", "Stephanie Quayle");
    enqueue(&pqueue, 2, song);

    song = createSong("Hotel", "Lena Stone");
    enqueue(&pqueue, 20, song);

    printQueue(pqueue, printSong);

    printf("--------------------------------------------------\n");

    while (queueLength(pqueue) > 0) {
        minPriority = getMinPriority(pqueue);
        printf("min priority = %d\n", minPriority);
        song = dequeue(&pqueue);
        printf("dequeued: ");
        printSong(song);
    }
}

int main() {
    pqueueTests();
}

