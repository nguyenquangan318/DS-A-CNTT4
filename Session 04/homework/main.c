#include <stdio.h>

int main(void) {
    //Nhap vao so hang, so cot va kiem tra
    int row, col;
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);
    if (row <= 0 || row > 1000 || col <= 0 || col > 1000) {
        printf("Invalid input\n");
        return 1;
    }
    //Nhap vao tung phan tu mang
    int arr[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    //In ra toan bo mang
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("arr [%d][%d] = %d\n", i, j, arr[i][j]);
        }
    }
    //Nhap vao hang can tinh tong va kiem tra
    int k;
    printf("Nhap so hang can tinh tong");
    scanf("%d", &k);
    if (k <= 0 || k > row) {
        printf("Invalid input\n");
        return 1;
    }
    //Tinh va in ra tong cac phan tu trong hang da nhap
    int sum = 0;
    for (int i = 0; i < col; i++) {
        sum += arr[k-1][i];
    }
    printf("Tong can tinh la: %d", sum);
    return 0;
}
