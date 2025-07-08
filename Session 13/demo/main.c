#include <stdio.h>
#include <stdlib.h>

//Cau truc du lieu stack
typedef struct Stack {
    //mang dai dien cho ngan xep
    int *arr;
    //Chi so phan tu tren cung ngan xep
    int top;
    //Kich thuoc cua ngan xep
    int cap;
} Stack;

//Xay dung ham khoi tao stack
Stack *createStack(int cap) {
    //B1: Cap phat bo nho cho stack
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    //B2: Gan cac gia tri thuoc ve stack (top, cap)
    stack->top = -1;
    stack->cap = cap;
    //B3: Cap phat bo nho cho mang dai dien
    stack->arr = (int *)malloc(sizeof(int) * cap);
    //B4: Tra ve dia chi ngan xep
    return stack;
}

//Xay dung ham kiem tra day stack
int isFull(Stack *stack) {
    if (stack->top == stack->cap - 1) {
        return 1;
    }
    return 0;
}

//Xay dung ham them phan tu vao stack
int push(Stack *stack, int val) {
    //B1: Kiem tra tran ngan xep
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return 0;
    }
    //B2: Tien hanh them phan tu vao stack
    //B2.1: Cap nhat gia tri top
    // stack->top = stack->top + 1;
    //B2.2: Dua phan tu vao mang
    // stack->arr[stack->top] = val;
    //B2.3: Tra ve ket qua
    stack->arr[++stack->top] = val;
    return 1;
}

//Xay dung ham kiem tra ngan xep trong
int isEmpty(Stack *stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}

//Xay dung ham lay phan tu khoi stack
int pop(Stack *stack) {
    //B1: Kiem tra ngan xep trong
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return 0;
    }
    //B2: Lay phan tu dau ngan xep
    //B2.1: Cap nhat gia tri top
    stack->top = stack->top - 1;
    // //B2.2: Tra ve gia tri duoc lay ra
    return stack->arr[stack->top + 1];
    // return stack->arr[stack->top--];
}

//Xay dung ham xem phan tu tren cung stack
int peek(Stack *stack) {
    //B1: Kiem tra stack trong
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return 0;
    }
    //B2: Tra ve phan tu co chi so la top
    return stack->arr[stack->top];
}

int main(void) {
    Stack *stack = createStack(3);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    // printf("%d\n", pop(stack));
    // printf("%d\n", pop(stack));
    // printf("%d\n", pop(stack));
    // pop(stack);
    printf("%d\n", peek(stack));
    pop(stack);
    printf("%d\n", peek(stack));
    printf("%d\n", peek(stack));
    return 0;
}