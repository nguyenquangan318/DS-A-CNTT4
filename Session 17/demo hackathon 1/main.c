#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//B1: Xay dung cac cau truc du lieu can thiet
typedef struct Course {
    int id;
    char title[20];
    int credit;
} Course;
typedef struct SingleNode {
    Course course;
    struct SingleNode *next;

} SingleNode;
typedef struct DoubleNode {
    Course course;
    struct DoubleNode *next;
    struct DoubleNode *prev;
} DoubleNode;
SingleNode *finishNode = NULL;
//B3: Xu ly yeu cau so 1
//B3.1: Xay dung ham khoi tao node trong DSLK don
SingleNode *createSingleNode(Course course) {
    SingleNode *node = (SingleNode *)malloc(sizeof(SingleNode));
    node->course = course;
    node->next = NULL;
    return node;
}
//B3.2: Xay dung ham them node vao cuoi DSLK don
SingleNode *insertSingleNodeAtEnd(SingleNode *head, Course course) {
    //B1: Khoi tao node can them
    SingleNode *newNode = createSingleNode(course);
    //B2: Xu ly truong hop danh sach trong
    if (head == NULL) {
        head = newNode;
        return head;
    }
    //B3: Duyet den cuoi danh sach
    SingleNode *temp = head;
    while (temp -> next != NULL) {
        temp = temp -> next;
    }
    //B4: Cap nhat con tro cua node cuoi
    temp -> next = newNode;
    return head;
}

//B4: Xu ly yeu cau so 2
void displaySingleList(SingleNode *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    //B4.1: Duyet qua tung node
    SingleNode *temp = head;
    while (temp != NULL) {
        //B4.2: In cac thong tin cua khoa hoc trong node
        printf("Course ID: %d\n", temp -> course.id);
        printf("Title: %s\n", temp -> course.title);
        printf("Credit: %d\n", temp -> course.credit);
        temp = temp -> next;
    }
}
//B5: Xu ly yeu cau so 3
SingleNode *deleteSingleNodeById(SingleNode *head, int id) {
    //B1: Kiem tra danh sach trong
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    //B2: Duyet den node co id hoac duyet het danh sach
    SingleNode *temp = head;
    SingleNode *prev = NULL;
    while (temp != NULL && temp -> course.id != id) {
        prev = temp;
        temp = temp -> next;
    }
    //B3: Neu duyet het danh sach thi thong bao va ket thuc
    if (temp == NULL) {
        printf("Khong tim thay course co id la %d", id);
        return head;
    }
    //B4: Neu tim thay node co id thi cap nhat con tro next cua node truoc do
    //Xu ly truong hop neu temp la node dau tien
    if (temp == head) {
        head = head -> next;
        finishNode = temp;
        free(temp);
        return head;
    }
    prev -> next = temp -> next;
    //B5: Giai phong node can xoa
    finishNode = temp;
    free(temp);
    return head;
}
//B6: Xu ly yeu cau so 4
void updateCourseById(SingleNode *head, int id) {
    //B1: Xu ly truong hop danh sach trong
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    //B2: Duyet den node co id hoac duyet het danh sach
    SingleNode *temp = head;
    while (temp != NULL && temp -> course.id != id) {
        temp = temp -> next;
    }
    //B3: Neu duyet het danh sach thi thong bao va ket thuc
    if (temp == NULL) {
        printf("Khong tim thay course co id la %d", id);
        return;
    }
    //B4: Neu tim thay node co id thi in thong tin khoa hoc cu
    printf("Course ID: %d\n", temp -> course.id);
    printf("Old title: %s\n", temp -> course.title);
    printf("Old credit: %d\n", temp -> course.credit);
    //B5: Yeu cau nhap thong tin moi cua khoa hoc
    printf("Nhap vao title moi: ");
    gets(temp -> course.title);
    printf("Nhap vao credit moi: ");
    scanf("%d", &temp -> course.credit);
}
//7: Xu ly yeu cau so 5
//B7.2: Xay dung ham khoi tao node trong DSLK doi
DoubleNode *createDoubleNode(Course course) {
    DoubleNode *node = (DoubleNode *)malloc(sizeof(DoubleNode));
    node->course = course;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
//B7.2: Xay dung ham them vao cuoi DSLK doi
DoubleNode *insertDoubleNodeAtEnd(DoubleNode *head, Course course) {
    //B1: Khoi tao node moi
    DoubleNode *newNode = createDoubleNode(course);
    //B2: Xu ly truong hop danh sach trong
    if (head == NULL) {
        head = newNode;
        return head;
    }
    //B3: Duyet den cuoi danh sach
    DoubleNode *temp = head;
    while (temp -> next != NULL) {
        temp = temp -> next;
    }
    //B4: Cap nhat cac con tro can thiet de tien hanh them
    temp -> next = newNode;
    newNode -> prev = temp;
    return head;
}
//B8: Xu ly yeu cau so 6

//B9: Xu ly yeu cau so 7
void searchCourseByTitle(SingleNode *head, char *findStr) {
    //B1: xu ly truong hop danh sach trong
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    //B2: Duyet toan bo danh sach
    SingleNode *temp = head;
    while (temp != NULL) {
        //B3: Neu co course nao co title chua findStr thi in thong tin course do
        if (strstr(temp -> course.title, findStr) == 0) {
            printf("Course ID: %d\n", temp -> course.id);
            printf("Title: %s\n", temp -> course.title);
            printf("Credit: %d\n", temp -> course.credit);
        }
    }

}

int main(void) {
    //B2: Xay dung menu
    int choice;
    //Khoi tao 2 danh sach lien ket
    SingleNode *singleHead = NULL;
    DoubleNode *doubleHead = NULL;
    do {
        printf("1. Them khoa hoc\n");
        printf("2. Hien thi toan bo khoa hoc\n");
        printf("3. Xoa khoa hoc\n");
        printf("4. Sua khoa hoc\n");
        printf("5. Danh dau khoa hoc hoan thanh\n");
        printf("6. Them khoa hoc\n");
        printf("7. Them khoa hoc\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                //B1: Khoi tao va nhap gia tri cho khoa hoc moi
                Course newCourse;
                printf("Nhap id: ");
                scanf("%d", &newCourse.id);
                fflush(stdin);
                printf("Nhap title: ");
                gets(newCourse.title);
                fflush(stdin);
                printf("Nhap credit: ");
                scanf("%d", &newCourse.credit);
                //B2: Goi ham them moi vao DSLK don
                singleHead = insertSingleNodeAtEnd(singleHead, newCourse);
                break;
            case 2:
                displaySingleList(singleHead);
                break;
            case 3:
                int deleteId;
                printf("Nhap id can xoa: ");
                scanf("%d", &deleteId);
                singleHead = deleteSingleNodeById(singleHead, deleteId);
                break;
            case 4:
                int updateId;
                printf("Nhap id can sua: ");
                scanf("%d", &updateId);
                updateCourseById(singleHead, updateId);
                break;
            case 5:
                int finishId;
                printf("Nhap id can danh dau hoan thanh: ");
                scanf("%d", &finishId);
                singleHead = deleteSingleNodeById(singleHead, finishId);
                if (finishNode == NULL) {
                    break;
                }
                Course finnishCourse;
                finnishCourse.id = finishNode -> course.id;
                finnishCourse.credit = finishNode -> course.credit;
                strcpy(finnishCourse.title, finishNode -> course.title);
                doubleHead = insertDoubleNodeAtEnd(doubleHead, finnishCourse);
                finishNode = NULL;
                break;
            case 6:
                break;
            case 7:
                char findStr[100];
                printf("Nhap ten khoa hoc muon tim: ");
                gets(findStr);
                searchCourseByTitle(singleHead, findStr);
                break;
            case 8:
                break;
            default:
                printf("Invalid choice");
        }
    } while (choice != 8);
    return 0;
}
