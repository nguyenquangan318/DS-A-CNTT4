#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

//Xay dung cau truc stack
typedef struct Stack {
    Node *head;
}Stack;

//Xay dung ham khoi tao stack
Stack *createStack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

//Xay dung ham them moi vao stack
void push(Stack *stack, int data) {
    //B1: Khoi tao node se duoc them vao ngan xep
    Node *newNode = createNode(data);
    //B2: Kiem tra tran ngan xep (kiem tra cap phat bo nho cho node)
    if (newNode == NULL) {
        printf("Stack overflow\n");
        return;
    }
    //B3: Tien hanh day node vao ngan xep (Them node vao dau danh sach)
    newNode->next = stack->head;
    stack->head = newNode;
}

//Xay dung ham lay ra khoi stack
void pop(Stack *stack) {
    //B1: Kiem tra ngan xep trong
    if (stack->head == NULL) {
        printf("Stack underflow\n");
        return;
    }
    //B2: Xoa node tren dinh ngan xep (Xoa node dau danh sach)
    Node *temp = stack->head;
    stack->head = stack->head->next;
    free(temp);
}

//Xay dung ham xem phan tu tren dinh ngan xep
int peek(Stack *stack) {
    //B1: Kiem tra ngan xep trong
    if (stack->head == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    //B2: Truy cap phan tu tren dinh ngan xep (Node dau danh sach)
    return stack->head->data;
}

int main(void) {
    printf("Hello, World!\n");
    return 0;
}