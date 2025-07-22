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

//Xay dung phuong thuc them vao cay
Node *insert(Node *root, int data) {
    //B1: Khoi tao node se duoc them
    Node *newNode = createNode(data);
    //Kiem tra cay trong
    if (root == NULL) {
        return newNode;
    }
    //B2: Khoi tao hang doi va dua node goc vao hang doi
    Queue *queue = createQueue(100);
    enqueue(queue, root);
    //B3: Trien khai vong lap den khi hang doi trong
    while (!isEmpty(queue)) {
        //B4: Lay node dau hang doi ra
        Node *node = dequeue(queue);
        //B5: Kiem tra con ben trai cua node
        if (node->left != NULL) {
            //B5.1: Neu co thi day con ben trai vao hang doi
            enqueue(queue, node->left);
        } else {
            //B5.2: Neu khong co thi chen node moi vao vi tri con ben trai
            node->left = newNode;
            free(queue->arr);
            free(queue);
            return root;
        }
        //B6: Kiem tra con ben phai cua node
        if (node->right != NULL) {
            //B6.1: Neu co thi day con ben phai vao hang doi
            enqueue(queue, node->right);
        } else {
            //B6.2: Neu khong co thi chen node moi vao vi tri con ben phai
            node->right = newNode;
            free(queue->arr);
            free(queue);
            return root;
        }
    }
}

//Xay dung phuong thuc xoa node khoi cay
Node *delete(Node *root, int data) {
    //B1: Kiem tra cay trong
    if (root == NULL) {
        return NULL;
    }
    //B2: Khoi tao hang doi va day root vao hang doi
    Queue *queue = createQueue(100);
    enqueue(queue, root);
    //B3: Khoi tao 3 node can thiet target, lastNode, lastParent
    Node *target = NULL;
    Node *lastNode = NULL;
    Node *lastParent = NULL;
    //B4: Trien khai vong lap den khi hang doi trong
    while (!isEmpty(queue)) {
        //B5: lay node dau hang doi ra
        Node *node = dequeue(queue);
        //B5.1: Kiem tra node co phai node can xoa va cap nhat target
        if (node->data == data) {
            target = node;
        }
        //B6: Kiem tra con ben trai cua node
        if (node->left != NULL) {
            //B6.1: day con ben trai vao hang doi
            enqueue(queue, node->left);
            //B6.2: cap nhat gia tri cua lastParent = node
            lastParent = node;
            //B6.3: cap nhat gia tri cua lastNode
            lastNode = node->left;
        }
        //B6: Kiem tra con ben phai cua node
        if (node->right != NULL) {
            //B6.1: day con ben phai vao hang doi
            enqueue(queue, node->right);
            //B6.2: cap nhat gia tri cua lastParent = node
            lastNode = node;
            //B6.3: cap nhat gia tri cua lastNode
            lastNode = node->right;
        }
    }

    //Thao tac xoa
    //B7: kiem tra target
    if (target == NULL) {
        free(queue->arr);
        free(queue);
        return root;
    }
    //B8: truong hop cay co nhieu hon 1 node
    if (lastNode != NULL) {
        //B8.1: cap nhat du lieu cua node can xoa
        target->data = lastNode->data;
        //B8.2: cap nhat con cua lastParent
        if (lastParent->left == lastNode) {
            //Kiem tra xem lastNode la con ben trai hay con ben phai
            lastParent->left = NULL;
        }else {
            lastParent->right = NULL;
        }
        //B8.3: giai phong lastNode
        free(lastNode);
    }else {
        //B9: truong hop cay co 1 node
        //B9.1: Giai phong node
        free(root);
        //B9.2: Gan lai root = NULL
        root = NULL;
    }
    //B10: Giai phong cac vung nho va tra ve root moi
    free(queue->arr);
    free(queue);
    return root;
}

int main(void) {
    return 0;
}
