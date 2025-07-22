#include <stdio.h>
#include <stdlib.h>

//B1: Xay dung cac cau truc du lieu can thiet
typedef struct Call {
    char *phone;
    int time;
} Call;
typedef struct Stack {
    Call *calls;
    int top;
    int capacity;
} Stack;
typedef struct Queue {
    Call *calls;
    int front;
    int rear;
    int capacity;
} Queue;
//B2: Xay dung cac ham khoi tao cau truc can thiet
Stack *createStack(int capacity) {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->calls = (Call *) malloc(stack->capacity * sizeof(Call));
    return stack;
}
Queue *createQueue(int capacity) {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->calls = (Call *) malloc(queue->capacity * sizeof(Call));
    return queue;
}
//B3: Xu ly yeu cau 1
//Xay dung ham kiem tra gioi han cua cau truc
int isStackfull(Stack *stack) {
    if (stack->top == stack->capacity - 1) {
        return 1;
    }
    return 0;
}
int isQueuefull(Queue *queue) {
    if (queue->rear == queue->capacity - 1) {
        return 1;
    }
    return 0;
}
//B3.1: Xay dung phuong thuc them vao stack
void push(Stack *stack, Call call) {
    //B1: Kiem tra gioi han stack
    if (isStackfull(stack)) {
        printf("Stack is full\n");
        return;
    }
    //B2: Cap nhat chi so top
    stack->top++;
    //B3: Dua cuoc goi vao ngan xep
    stack->calls[stack->top] = call;
}
//B3.2: Xay dung phuong thuc them vao queue
void enqueue(Queue *queue, Call call) {
    //B1: Kiem tra gioi han queue
    if (isQueuefull(queue)) {
        printf("Queue is full\n");
        return;
    }
    //B2: Cap nhat chi so rear
    queue->rear++;
    //B3: Dua cuoc goi vao hang doi
    queue->calls[queue->rear] = call;
}
//B4: Xu ly yeu cau 2
//Xay dung ham kiem tra stack trong
int isStackEmpty(Stack *stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}
//B4.1: Xay dung ham lay ra khoi ngan xep
Call* pop(Stack *stack) {
    //B1: Kiem tra stack trong
    if (isStackEmpty(stack)) {
        printf("Stack is empty\n");
        return NULL;
    }
    //B2: Luu lai gia tri tren dinh stack hien tai
    Call *call = &stack->calls[stack->top];
    //B3: Giam chi so top
    stack->top--;
    //B4: Tra ve gia tri bi xoa
    return call;
}
//B5: Xu ly yeu cau 3
//B6: Xu ly yeu cau 4
//B6.1: Xay dung ham hien thi toan bo hang doi
void displayQueue(Queue *queue) {
    //B1: Kiem tra hang doi trong
    if (queue->front > queue->rear) {
        printf("Queue is empty\n");
        return;
    }
    //B2: su dung vong lap tu front - rear de hien thi toan bo cuoc goi
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("phone: %s\n", queue->calls[i].phone);
        printf("time: %d\n", queue->calls[i].time);
    }
}
int main(void) {
    //B3: Xay dung menu
    int choice;
    Stack *backStack = createStack(10);
    Stack *forwardStack = createStack(10);
    Queue *historyQueue = createQueue(10);
    do {
        printf("1. CALL\n");
        printf("2. BACK\n");
        printf("3. REDIAL\n");
        printf("4. HISTORY\n");
        printf("5. EXIT\n");
        printf("\nEnter your choice: ");
        switch (choice) {
            case 1:
                //B1: Khoi tao va yeu cau nguoi dung nhap
                Call newCall;
                printf("Enter the phone number: ");
                gets(newCall.phone);
                newCall.time = 10;
                //B2: Dua cuoc goi vao backStack
                push(backStack, newCall);
                //B3: Dua cuoc goi vao historyQueue
                enqueue(historyQueue, newCall);
                //B4: Reset fowardStack
                forwardStack = createStack(10);
                break;
            case 2:
                //B1: Lay cuoc goi gan nhat tu backStack
                Call *backCall;
                backCall = pop(backStack);
                //B2: Dua cuoc goi lay duoc vao forwardStack
                if (backCall == NULL) {
                    break;
                }
                push(forwardStack, *backCall);
                break;
            case 3:
                //B1: Lay cuoc goi tren dinh foward stack
                Call *forwardCall = pop(forwardStack);
                if (forwardCall == NULL) {
                    break;
                }
                //B2: Dua cuoc goi vao queue va backstack
                push(backStack, *forwardCall);
                enqueue(historyQueue, *forwardCall);
                break;
            case 4:
                displayQueue(historyQueue);
                break;
            case 5:
                printf("Thoat chuong trinh");
                break;
            default:
                printf("Invalid choice");
        }
        scanf("%d", &choice);
    } while (choice != 5);
    return 0;
}
