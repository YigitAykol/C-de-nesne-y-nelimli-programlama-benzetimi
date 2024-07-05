#ifndef CANLI_QUEUE_H
#define CANLI_QUEUE_H

#include "Canli.h"
#include <stdbool.h>

typedef struct CanliNode {
    Canli* canli;
    struct CanliNode* next;
    int a;
    
} CanliNode;

typedef struct {
    CanliNode* head;
    CanliNode* tail;
} CanliQueue;

void enqueue(CanliQueue* queue, Canli* canli);
Canli* dequeue(CanliQueue* queue);
void printQueue(CanliQueue* queue);
void canlilarikarsilastirX(CanliQueue* queue);

#endif
