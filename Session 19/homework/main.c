#include <stdio.h>
#include <stdlib.h>

//B1: xay dung cau truc du lieu can thiet
typedef struct Queue {
    int *arr;
    int capacity;
    int front;
    int rear;
}Queue;
//B2: Xay dung ham khoi tao
Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (int *)malloc(sizeof(int) * capacity);
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
}
//B3: xay dung cac phuong thuc lam viec voi hang doi
//B3.1: Kiem tra hang doi day
int isFull(Queue *queue) {
    if (queue->rear == queue->capacity - 1) {
        return 1;
    }
    return 0;
}
//B3.2: Them vao hang doi
void enQueue(Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = item;
}
//B3.3: Kiem tra hang doi trong
int isEmpty(Queue *queue) {
    if (queue->front> queue->rear) {
        return 1;
    }
    return 0;
}
//B3.4: Lay ra khoi hang doi
void deQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    queue->rear--;
}

int main(void) {
    printf("Hello, World!\n");
    return 0;
}