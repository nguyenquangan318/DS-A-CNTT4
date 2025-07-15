#include <stdio.h>
#include <stdlib.h>

//Xay dung cau truc du lieu queue
typedef struct Queue {
    int *arr;
    int front;
    int rear;
    int capacity;
} Queue;

//Xay dung ham khoi tao queue
Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (int *)malloc(sizeof(int) * capacity);
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}
//Xay dung ham them vao hang doi
void enQueue(Queue *queue, int value) {
    //B1: Kiem tra hang doi (Mang khong con vi tri de them)
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    //B2: Tang chi so rear len
    queue->rear = queue->rear + 1;
    //B3: Them gia tri vao vi tri rear
    queue->arr[queue->rear] = value;
}
//Xay dung ham lay khoi hang doi
void deQueue(Queue *queue) {
    //B1: Kiem tra hang doi trong
    if (queue->rear < queue->front) {
        printf("Queue is empty\n");
        return;
    }
    //B2: Tang gia tri front len
    queue->front = queue->front + 1;
}
//Xay dung ham xem phan tu dau hang doi
int getFront(Queue *queue) {
    //B1: Kiem tra hang doi trong
    if (queue->rear < queue->front) {
        printf("Queue is empty\n");
        return -1;
    }
    //B2: Tra ve phan tu co chi so la front
    return queue->arr[queue->front];
}
//Xay dung ham in toan bo hang doi
void displayQueue(Queue *queue) {
    //B1: Kiem tra hang doi trong
    if (queue->rear < queue->front) {
        printf("Queue is empty\n");
        return;
    }
    //B2: Tien hanh in cac phan tu co chi so tu front den rear
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
}

int main(void) {
    Queue *queue = createQueue(5);
    return 0;
}