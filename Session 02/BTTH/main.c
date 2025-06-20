#include <stdio.h>
#include <stdlib.h>

int *insertToArray(int *arr, int *size, int value);
void printArray(int *arr, int size);
int *deleteFromArray(int *arr, int *size, int pos);

int main(void) {
    int choice;
    int *numbers = NULL;
    int size = 0;
    do {
        printf("\t MENU\n");
        printf("1. Them phan tu\n");
        printf("2. Hien thi mang\n");
        printf("3. Xoa phan tu\n");
        printf("4. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                numbers = insertToArray(numbers, &size, 1);
                numbers = insertToArray(numbers, &size, 2);
                numbers = insertToArray(numbers, &size, 3);
                numbers = insertToArray(numbers, &size, 4);
                break;
            case 2:
                printArray(numbers, size);
                break;
            case 3:
                numbers = deleteFromArray(numbers, &size, 2);
                break;
            case 4:
                break;
            default:
                printf("Lua chon khong hop le");
        }
    } while (choice != 4);
    return 0;
}

int *insertToArray(int *arr, int *size, int value) {
    //B1: Cap phat lai bo nho cho mang duoc truyen vao
    arr = (int *) realloc(arr, sizeof(int) * (*size + 1));
    //B2: Gan lai gia tri cua phan tu cuoi cung cua mang duoc cap phat
    arr[*size] = value;
    //B3: Cap nhat size
    (*size)++;
    //B4: Tra ve mang (con tro) duoc cap phat
    return arr;
}
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("numbers[%d] = %d \n", i, arr[i]);
    }
}
int *deleteFromArray(int *arr, int *size, int pos) {
    //B1: dich cac phan tu tu pos - size ve ben trai
    for (int i = pos; i < *size-1; i++) {
        arr[i] = arr[i + 1];
    }
    //B2: Cap phat lai cho mang
    arr = (int * )realloc(arr, sizeof(int) * (*size - 1));
    //B3: Cap nhat lai size
    (*size)--;
    //B4: tra ve mang (con tro)
    return arr;
}