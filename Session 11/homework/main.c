#include <stdio.h>
#include <stdlib.h>

//Khoi tao cau truc cua 1 node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

//Ham khoi tao 1 phan tu
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Ham them vao node vi tri bat ky trong DSLK don
Node *insertAtPos(Node *head, int data, int pos) {
    //B1: Xu ly truong hop pos < 0
    if (pos < 0) {
        return head;
    }
    //B2: Xu ly truong hop pos == 0
    if (pos == 0) {
        //B2.1: Khoi tao node moi
        Node *newNode = createNode(data);
        //B2.2: Cap nhat con tro next cua node moi -> head
        newNode->next = head;
        //B2.3: Cap nhat head
        head = newNode;
        //B2.4: Tra ve head
        return head;
    }
    //B3: Xu ly truong hop pos > 0
    Node *current = head;
    //B3.1: Duyet den node truoc vi tri can them hoac den cuoi danh sach
    for (int i = 0; i < pos - 1 && current != NULL; i++) {
        current = current->next;
    }
    //B3.2: Neu duyet den NULL thi ket thuc
    if (current == NULL) {
        return head;
    }
    //B3.3: Cap nhat cac con tro can thiet de them
    Node *newNode = createNode(data);
    newNode->next = current->next;
    current->next = newNode;
    //B3.4: Tra ve head moi
    return head;
}

//Ham xoa node o vi tri bat ky trong DSLK don
Node *deleteAtPos(Node *head, int pos) {
    Node *current = head;
    //B1: Xu ly truong hop pos < 0
    if (pos < 0) {
        return head;
    }
    //B2: Xu ly truong hop danh sach chi co 1 node
    if (head -> next == NULL) {
        //B2.1: Giai phong node duy nhat
        free(head);
        //B2.2: Gan lai head = NULL
        head = NULL;
        //B2.3: Tra ve head moi
        return head;
    }
    //B3: Xu ly truong hop pos == 0
    if (pos == 0) {
        //B3.1: Cap nhat head
        head = current->next;
        //B3.2: Giai phong node dau tien
        free(current);
        //B3.3: Tra ve head moi
        return head;
    }
    //B4: Xu ly truong hop pos > 0
    //B4.1: Duyet den node o vi tri can xoa hoac den cuoi danh sach
    Node *previous = NULL;
    for (int i = 0; i < pos && current != NULL; i++) {
        previous = current;
        current = current->next;
    }
    //B4.2: Xu ly truong hop pos nam ngoai danh sach
    if (current == NULL) {
        return head;
    }
    //B4.3: Cap nhat cac con tro can thiet de xoa
    previous->next = current->next;
    //B4.4: Giai phong phan tu o vi tri can xoa
    free(current);
    //B4.5: tra ve head moi
    return head;
}

int main(void) {
    printf("Hello, World!\n");
    return 0;
}