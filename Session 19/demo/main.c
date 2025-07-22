#include <stdio.h>
#include <stdlib.h>

//B1: Xay dung cau truc can thiet
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;
//B2: Xay dung ham khoi tao node
Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//B3: xay dung cac phuong thuc cua cay
//B3.1: Xay dung ham preorder
void preorderDFS(Node *root) {
    //Xay dung dieu kien dung
    if (root == NULL) {
        return;
    }
    //In ra node dang duoc xet
    printf("%d ", root->data);
    //Giai quyet bai toan voi cay con ben tay trai
    preorderDFS(root->left);
    //Giai quyet bai toan voi cay con ben tay trai
    preorderDFS(root->right);
}
//B3.2: Xay dung ham inorder
void inorderDFS(Node *root) {
    //Xay dung dieu kien dung
    if (root == NULL) {
        return;
    }
    //Giai quyet bai toan voi cay con ben trai
    inorderDFS(root->left);
    //In node duoc xet
    printf("%d ", root->data);
    //Giai quyet bai toan voi cay con ben phai
    inorderDFS(root->right);
}
//B3.3: Xay dung ham postorder
void postorderDFS(Node *root) {
    //Xay dung dieu kien dung
    if (root == NULL) {
        return;
    }
    //Giai quyet bai toan voi cay con ben trai
    postorderDFS(root->left);
    //Giai quyet bai toan voi cay con ben phai
    postorderDFS(root->right);
    //In node dang duoc xet
    printf("%d ", root->data);
}

//B3.4: Xay dung ham levelorder
//B1: Xay dung cau truc hang doi
typedef struct Queue {
    Node **arr;
    int capacity;
    int front;
    int rear;
} Queue;
//B2: Xay dung ham khoi tao hang doi
Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (Node **)malloc(sizeof(Node *) * capacity);
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}
//B3: Xay dung ham kiem tra hang doi trong
int isEmpty(Queue *queue) {
    if (queue->rear == queue->capacity - 1) {
        return 1;
    }
    return 0;
}
//B4: Xay dung ham them phan tu vao hang doi
void enqueue(Queue *queue, Node *node) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = node;
}
void levelorderBFS(Node *root) {
    //B1: Kiem tra cay rong
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    //B2: Khoi tao hang doi
    Queue *queue = createQueue(100);
    //B3: Dua root vao hang doi
    enqueue(queue, root);
    //B4: Thuc hien vong lap den khi hang doi trong
    while (!isEmpty(queue)) {
        //B5: Lay node ra khoi hang doi va in ra
        Node *node = queue->arr[queue->front++];
        printf("%d ", node->data);
        //B6: Kiem tra va them con trai vao hang doi
        if (node->left != NULL) {
            enqueue(queue, node->left);
        }
        //B7: Kiem tra va them con trai vao hang doi
        if (node->right != NULL) {
            enqueue(queue, node->right);
        }
    }
    free(queue);
}
int main(void) {
    Node *root = NULL;
    root = createNode(1);
    Node *node1 = createNode(2);
    Node *node2 = createNode(3);
    Node *node3 = createNode(4);
    Node *node4 = createNode(5);
    Node *node5 = createNode(6);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->right = node5;
    printf("Preorder DFS: \n");
    preorderDFS(root);
    printf("\n");
    printf("Inorder DFS: \n");
    inorderDFS(root);
    printf("\n");
    printf("Postorder DFS: \n");
    postorderDFS(root);
    printf("\n");
    printf("Level order BFS: \n");
    levelorderBFS(root);
    return 0;
}