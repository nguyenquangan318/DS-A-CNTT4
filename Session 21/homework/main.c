#include <stdio.h>
#include <stdlib.h>

//B1: Xay dung cau truc cua 1 node
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;
//B2: Xay dung ham khoi tao node
Node *createNode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
//Xay dung cau truc hang doi
typedef struct Queue {
    Node **arr;
    int capacity;
    int front;
    int rear;
} Queue;
//Xay dung ham khoi tao hang doi
Queue *createQueue(int capacity) {
    Queue *newQueue = (Queue *) malloc(sizeof(Queue));
    newQueue->arr = (Node **) malloc(sizeof(Node *) * capacity);
    newQueue->capacity = capacity;
    newQueue->front = 0;
    newQueue->rear = -1;
    return newQueue;
}
//Xay dung phuong thuc them vao hang doi
void enqueue(Queue *queue, Node *node) {
    //Kiem tra hang doi day
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    //Day phan tu vao hang doi
    queue->arr[++queue->rear] = node;
}
//Xay dung phuong thuc kiem tra hang doi trong
int isEmpty(Queue *queue) {
    if (queue->rear < queue->front) {
        return 1;
    }
    return 0;
}
//Xay dung phuong thuc lay ra khoi hang doi
Node *dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return NULL;
    }
    return queue->arr[queue->front++];
}
//Xay dung phuong thuc xoa khoi hang doi
Node *deleteTreeNode(Node *root, int data) {
    //Tim cac node can thiet target, lastNode, lastParent
    //B1: Khoi tao hang doi va dua goc vao hang doi
    Queue *queue = createQueue(100);
    enqueue(queue, root);
    //B2: Khoi tao 3 node can thiet cho thao tac xoa
    Node *target = NULL;
    Node *lastNode = NULL;
    Node *lastParent = NULL;
    //B3: Trien khai vong lap den khi hang doi trong
    while (!isEmpty(queue)) {
        //B4: Lay node dau hang doi
        Node * currentNode = dequeue(queue);
        //B5: So sanh va gan lai gia tri cho target
        if (currentNode->data == data) {
            target = currentNode;
        }
        //B6: Kiem tra con ben trai cua node
        if (currentNode->left != NULL) {
            enqueue(queue, currentNode->left);
            //B6.1: Gan lai gia tri cho lastNode va lastParent
            lastNode = currentNode->left;
            lastParent = currentNode;
        }
        //B7: Kiem tra con ben phai cua node
        if (currentNode->right != NULL) {
            enqueue(queue, currentNode->right);
            //B7.1: Gan lai gia tri cho lastNode va lastParent
            lastNode = currentNode->right;
            lastParent = currentNode;
        }
    }
    //Thuc hien xoa
    //B1: Ghi de du lieu cua target
    target->data = lastNode->data;
    //B2: Gan lai con cua lastParent thanh NULL
    if (lastParent->left == lastNode) {
        lastParent->left = NULL;
    }else {
        lastParent->right = NULL;
    }
    //B3: Giai phong lastNode
    free(lastNode);
    return root;
}

int main(void) {
    return 0;
}