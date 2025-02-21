#include "Student.h"
#ifndef QUEUE_HEADER
#define QUEUE_HEADER
#define TOTAL_SIZE 1000

typedef Student ElementType;

typedef struct {
    ElementType elements[TOTAL_SIZE];
    int _size;
    int _front;
    int _rear;
} Queue;

void QueueInit(Queue *que);
ElementType QueueFront(Queue *que);
int QueueEmpty(Queue *que);
int QueueFull(Queue *que);
void QueueEnqueue(Queue *que, ElementType element);
ElementType QueueDequeue(Queue *que);
int QueueSize(Queue *que);

#endif
