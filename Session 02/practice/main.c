#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int x;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    if (n < 0 || n > 100) {
        printf("So luong phan tu khong hop le!");
        return 0;
    }

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho dong!");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu tai vi tri %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Nhap vi tri index muon xoa: ");
    scanf("%d", &x);
    if (x > n || x < 0) {
        printf("Vi tri xoa khong hop le!");
        return 0;
    }
    for (int i = x; i <= n; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    printf("Mang sau khi xoa la: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
}