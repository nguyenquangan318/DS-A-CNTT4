#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    //B1: Khoi tao mang 2 mang con ben trai va ben phai
    int leftLength = mid - left + 1;
    int rightLength = right - mid;
    int leftArr[leftLength], rightArr[rightLength];
    //B2: Sao chep cac gia tri tu mang ban dau vao 2 mang con
    for (int i = 0; i < leftLength; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < rightLength; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }
    //B3: Tron 2 mang con lai trong mang ban dau
    int lefArrIndex = 0;
    int rightArrIndex = 0;
    int arrIndex = left;
    //Tron tung phan tu trong 2 mang con
    while ((lefArrIndex < leftLength) && (rightArrIndex < rightLength)) {
        if (leftArr[lefArrIndex] <= rightArr[rightArrIndex]) {
            arr[arrIndex] = leftArr[lefArrIndex];
            lefArrIndex++;
        }else {
            arr[arrIndex] = rightArr[rightArrIndex];
            rightArrIndex++;
        }
        arrIndex++;
    }
    //Tron cac phan tu con lai trong mang con ben trai
    while (lefArrIndex < leftLength) {
        arr[arrIndex] = leftArr[lefArrIndex];
        lefArrIndex++;
        arrIndex++;
    }
    //Tron cac phan tu con lai trong mang con ben phai
    while (rightArrIndex < rightLength) {
        arr[arrIndex] = rightArr[rightArrIndex];
        rightArrIndex++;
        arrIndex++;
    }
}

void mergeSort(int arr[], int left, int right) {
    //Xay dung dieu kien dung
    if (left == right) {
        return;
    }
    int mid = (left + right) / 2;
    //Giai quyet bai toan con voi mang ben trai
    mergeSort(arr, left, mid);
    //Giai quyet bai toan con voi mang ben phai
    mergeSort(arr, mid + 1, right);
    //Tien hanh tron 2 mang con lai trong mang ban dau
    merge(arr, left, mid, right);
}

int main(void) {
    return 0;
}