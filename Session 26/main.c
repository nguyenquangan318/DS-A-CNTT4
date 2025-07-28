#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char string[50] = "";

//Xay dung cac cau truc can thiet
typedef struct Operation {
    char action;
    char value;
} Operation;

typedef struct Stack {
    Operation *operations;
    int capacity;
    int top;
} Stack;

Stack *createStack(int capacity) {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->operations = (Operation *) malloc(sizeof(Operation) * capacity);
    stack->capacity = capacity;
    stack->top = -1;
    return stack;
}

//Ham them ky tu vao chuoi
void insertToString(char character) {
    int length = strlen(string);
    string[length] = character;
    string[length + 1] = '\0';
}

//Ham xoa ky tu khoi chuoi
void deleteFromString() {
    int length = strlen(string);
    string[length - 1] = '\0';
}

//Ham day tien trinh vao stack
void push(Stack *stack, Operation operation) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack is full\n");
        return;
    }
    stack->top++;
    stack->operations[stack->top] = operation;
}

//Ham kiem tra stack trong
int isEmpty(Stack *stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}

//Ham lay ra khoi ngan xep
Operation pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    return stack->operations[stack->top--];
}

int main(void) {
    int choice;
    Stack *UNDO = createStack(100);
    Stack *REDO = createStack(100);
    //Khoi tao tien trinh
    Operation operation;
    do {
        printf("1. INSERT\n");
        printf("2. UNDO\n");
        printf("3. REDO\n");
        printf("4. PRINT\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                char character;
                printf("Enter character: ");
                fflush(stdin);
                scanf("%c", &character);
                insertToString(character);
                //Day tien trinh vao stack UNDO
                operation.action = 'I';
                operation.value = character;
                push(UNDO, operation);
                printf("Chuoi sau khi insert: ");
                printf("%s\n", string);
                break;
            case 2:
                if (isEmpty(UNDO)) {
                    printf("UNDO is empty\n");
                    break;
                }
                operation = pop(UNDO);
                deleteFromString();
                push(REDO, operation);
                printf("Chuoi sau khi UNDO: ");
                printf("%s\n", string);
                break;
            case 3:
                if (isEmpty(REDO)) {
                    printf("REDO is empty\n");
                    break;
                }
                operation = pop(REDO);
                printf("%c\n", operation.value);
                insertToString(operation.value);
                push(UNDO, operation);
                printf("Chuoi sau khi REDO: ");
                printf("%s\n", string);
                break;
            case 4:
                printf("Chuoi: ");
                printf("%s\n", string);
                break;
            case 5:
                printf("Thoat chuong trinh");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
    return 0;
}
