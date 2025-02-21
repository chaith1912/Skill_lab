#include "queue.h"
#include <stdio.h>

#define MAX_QUEUE_SIZE 100

typedef int ElementType;

typedef struct {
    ElementType elements[MAX_QUEUE_SIZE];
    int _size;
    int _front;
    int _rear;
} Queue;

void QueueInit(Queue *que) {
    que->_size = 0;
    que->_front = 0;
    que->_rear = -1;
}

int QueueEmpty(Queue *que) {
    return (que->_size == 0);
}

int QueueFull(Queue *que) {
    return (que->_size == MAX_QUEUE_SIZE);
}

void QueueEnqueue(Queue *que, ElementType element) {
    if (QueueFull(que)) {
        printf("Queue Full\n");
        return;
    }
    que->_rear = (que->_rear + 1) % MAX_QUEUE_SIZE;
    que->elements[que->_rear] = element;
    que->_size++;
}

ElementType QueueDequeue(Queue *que) {
    if (QueueEmpty(que)) {
        printf("Queue Empty\n");
        return -1;
    }
    ElementType element = que->elements[que->_front];
    que->_front = (que->_front + 1) % MAX_QUEUE_SIZE;
    que->_size--;
    return element;
}

ElementType QueueFront(Queue *que) {
    if (QueueEmpty(que)) {
        printf("Queue Empty\n");
        return -1;
    }
    return que->elements[que->_front];
}

int QueueSize(Queue *que) {
    return que->_size;
}
