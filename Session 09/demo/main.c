#include <stdio.h>
#include <stdlib.h>

//Xay dung cau truc cho mot phan tu trong danh sach
typedef struct Node {
    int data;
    struct Node *next;
} Node;

//Xay dung ham tao phan tu
Node *createNode(int data) {
    //B1: Cap phat bo nho cho mot phan tu
    Node *node = (Node *)malloc(sizeof(Node));
    //B2: gan gia tri cho du lieu cua phan tu
    node->data = data;
    //B3: gan nut tiep theo cho phan tu
    node->next = NULL;
    //B4: Tra ve con tro den phan tu
    return node;
}

//Xay dung ham in toan bo danh sach lien ket
void printList(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

//Xay dung ham them vao cuoi danh sach lien ket
Node *insertAtEnd(Node *head) {
    //B1: Khoi tao node moi
    Node *newNode = createNode(4);
    //B2: Kiem tra xem danh sach lien ket co trong khong
    if (head == NULL) {
        head = newNode;
        return head;
    }
    //B3: Duyet den cuoi danh sach lien ket
    Node *lastNode = head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    //B4: gan lai con tro cho node cuoi danh sach
    lastNode->next = newNode;
    //B5: Tra ve danh sach moi
    return head;
}

//Xay dung ham xoa o cuoi danh sach lien ket
Node *deleteAtEnd(Node *head) {
    //B1: Kiem tra danh sach trong
    if (head == NULL) {
        return head;
    }
    //B2: Kiem tra danh sach chi co 1 phan tu
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    //B3: Duyet den phan tu gan cuoi
    Node *secondLastNode = head;
    while (secondLastNode->next->next != NULL) {
        secondLastNode = secondLastNode->next;
    }
    //B4: Giai phong phan tu cuoi cung
    free(secondLastNode->next);
    //B5: Gan lai con tro cua node cuoi cung moi
    secondLastNode->next = NULL;
    //B6: Tra ve danh sach moi
    return head;
}

int main(void) {
    //Khoi tao danh sach lien ket
    Node *head = NULL;
    Node *node1 = createNode(1);
    Node *node2 = createNode(2);
    Node *node3 = createNode(3);

    head = node1;
    node1->next = node2;
    node2->next = node3;

    printList(head);
    head = insertAtEnd(head);
    printList(head);
    head = deleteAtEnd(head);
    head = deleteAtEnd(head);
    printList(head);
    return 0;
}