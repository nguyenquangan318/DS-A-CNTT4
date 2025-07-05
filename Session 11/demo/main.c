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
    Node *newNode = (Node *)malloc(sizeof(Node));
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
        }else {
            printf("<-->");
        }
        current = current->next;
    }
    printf("NULL");
    printf("\n");
}

//Xay dung ham them vao cuoi
Node *insertAtEnd(Node *head, int data) {
    Node *newNode = createNode(data);
    //B1: Xu ly truong hop danh sach trong
    if (head == NULL) {
        head = newNode;
    }else {
        //B2: Xu ly truong hop con lai
        //B2.1: Duyet den node cuoi cung
        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        //B2.2: Cap nhat cac con tro can thiet de them
        current->next = newNode;
        newNode->prev = current;
    }
    //B3: Tra ve head moi
    return head;
}

//Xay dung ham xoa o cuoi
Node *deleteAtEnd(Node *head) {
    //B1: Xu ly truong hop danh sach trong
    if (head == NULL) {
        return head;
    }
    //B2: Xu ly truong hop danh sach chi co 1 phan tu
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return head;
    }
    //B3: Duyet den node cuoi cung
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    //B4: Cap nhat con tro can thiet
    current->prev->next = NULL;
    //B5: Giai phong node cuoi cung
    free(current);
    //B6: Tra ve head moi
    return head;
}


int main(void) {
    //Tao ra 3 node va lien ket chung lai voi nhau
    Node *head = createNode(1);
    Node *node2 = createNode(2);
    Node *node3 = createNode(3);

    head->next = node2;
    node2->prev = head;
    node3->prev = node2;
    node2->next = node3;
    display(head);

    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);
    display(head);


    return 0;
}