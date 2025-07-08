#include <stdio.h>
#include <stdlib.h>

//Xay dung cau truc cho mot node
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

//Xay dung ham khoi tao node
Node *createNode(int data) {
    //B1: Cap phat bo nho cho node moi
    Node *newNode = (Node *) malloc(sizeof(Node));
    //B2: Gan gia tri
    newNode->data = data;
    //B3: Gan cac con tro
    newNode->next = NULL;
    newNode->prev = NULL;
    //B4: Tra ve dia chi cua node moi
    return newNode;
}

//Xay dung ham duyet toan bo danh sach
void display(Node *head) {
    Node *current = head;
    printf("NULL<-");
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next == NULL) {
            printf("->");
        } else {
            printf("<-->");
        }
        current = current->next;
    }
    printf("NULL");
    printf("\n");
}

//Xay dung ham them vao vi tri bat ky
Node *insertAtPosition(Node *head, int data, int pos) {
    //B1: Xu ly truong hop pos < 0
    if (pos < 0) {
        return head;
    }
    //B2: Khoi tao node moi
    Node *newNode = createNode(data);
    //B3: Xu ly truong hop pos == 0
    if (pos == 0) {
        //B3.1: Xu ly truong hop danh sach khong trong
        if (head != NULL) {
            newNode->next = head;
            head->prev = newNode;
        }
        //B3.2: Gan lai head moi
        head = newNode;
        //B3.3: Tra ve head moi
        return head;
    }
    //B4: Xu ly truong hop pos > 0
    //B4.1: Duyet den phan tu nam truoc vi tri can them hoac den cuoi
    Node *current = head;
    for (int i = 0; i < pos - 1 && current != NULL; i++) {
        current = current->next;
    }
    //B4.2: Neu duyet den cuoi thi tra ve va ket thuc
    if (current == NULL) {
        return head;
    }
    //B4.3: Cap nhat cac con tro can thiet de them
    newNode->next = current->next;
    newNode->prev = current;
    current->next = newNode;
    if (newNode -> next != NULL) {
        newNode->next->prev = newNode;
    }
    //B4.4: Tra ve head moi
    return head;
}

//Xay dung ham xoa tai vi tri bat ky
Node *deleteAtPos(Node *head, int pos) {
    //B1: Xu ly truong hop pos < 0 hoac danh sach trong
    if (pos< 0 || head == NULL) {
        return head;
    }
    //B2: Xu ly truong hop pos >=0
    //B2.1: Duyet den vi tri can xoa hoac den het danh sach
    Node *current = head;
    for (int i = 0; i < pos && current != NULL; i++) {
        current = current->next;
    }
    //B2.2: Xu ly truong hop duyet het danh sach
    if (current == NULL) {
        return head;
    }
    //B2.3: Cap nhat cac con tro can thiet de xoa
    if (current != head) {
        //Truong hop xoa node dau thi khong cap nhat con tro
        current->prev->next = current->next;
    }
    if (current -> next != NULL) {
        //Truong hop xoa node cuoi thi khong cap nhat con tro
        current->next->prev = current->prev;
    }
    if (current == head) {
        head = current->next;
    }
    //B2.4: Tra ve head moi
    return head;
}

int main(void) {
    printf("Hello, World!\n");
    return 0;
}
