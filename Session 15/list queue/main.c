#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

//Xay dung cau truc queue
    typedef struct Queue {
        Node *front;
        Node *rear;
    } Queue;

//Xay dung ham khoi tao hang doi
Queue *createQueue() {
    //B1: Cap phat bo nho cho hang doi
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    //B2: Gan cac gia tri
    queue->front = queue->rear = NULL;
    return queue;
}

//Xay dung ham them phan tu vao hang doi
void enQueue(Queue *queue, int data) {
    //B1: Khoi tao node va kiem tra tran bo nho
    Node *newNode = createNode(data);
    if (newNode == NULL) {
        printf("Queue is full\n");
        return;
    }
    //B2: Xu ly truong hop hang doi trong (queue->front == NULL)
    if (queue->front == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    //B3: Them node moi vao cuoi danh sach
    queue->rear->next = newNode;
    //B4: Cap nhat phan tu cuoi hang doi
    queue->rear = newNode;
}

//Xay dung ham xoa phan tu khoi hang doi
void deQueue(Queue *queue) {
    //B1: Xu ly truong hop hang doi trong (queue -> front == NULL)
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    //B2: Luu lai node dau hang doi hien tai
    Node *temp = queue->front;
    //B3: Cap nhat con tro front
    queue->front = queue->front->next;
    //B3.1: Xu ly truong hop hang doi chi co 1 node
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    //B4: Giai phong node dau hang cu
    free(temp);
}

//Xay dung ham in toan bo hang doi
void displayQueue(Queue *queue) {
    //B1: Xu ly truong hop hang doi trong
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    //B2: Duyet toan bo danh sach tu dau de hien thi
    Node *temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(void) {
    Queue *queue = createQueue();
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    displayQueue(queue);
    deQueue(queue);
    deQueue(queue);
    deQueue(queue);
    displayQueue(queue);
    return 0;
}
