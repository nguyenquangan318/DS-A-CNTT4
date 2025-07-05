#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
    //Dieu kien dung khi khong tim thay
    if (low> high) {
        return -1;
    }
    //Dieu kien dung khi tim thay
    int mid = (low + high) / 2;
    if (arr[mid] == key) {
        return mid;
    }
    if (key < arr[mid]) {
        //Bai toan con o nua dau
        binarySearch(arr, low, mid - 1, key);
    }else {
        //Bai toan con o nua sau
        binarySearch(arr, mid + 1, high, key);
    }
}
int main(void) {
    printf("Hello, World!\n");
    return 0;
}