#include <stdio.h>

//Xay dung ham phan vung
int partition(int array[], int low, int high) {
    //B1: Lay phan tu lam moc (phan tu cuoi cung)
    int pivot = array[high];
    //B2: Khoi tao vi tri can chen = low - 1
    int i = low - 1;
    //B3: Thuc hien dua cac phan tu nho hon ve truoc va cac phan tu lon hon ve sau vi tri
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    //B4: Doi cho phan tu moc voi phan tu o vi tri can chen
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    //B5: Tra ve vi tri can chen
    return i + 1;
}

//Xay dung ham sap xep nhanh
void quickSort(int arr[], int low, int high) {
    //Dieu kien dung: khi phan can phan vung co it hon hoac bang 1 phan tu
    if (low < high) {
        //B1: Thuc hien phan vung dua tren phan tu moc
        int pivotPos = partition(arr, low, high);
        //B2: Giai quyet bai toan con voi nua ben trai cua moc
        quickSort(arr, low, pivotPos - 1);
        //B3: Giai quyet bai toan con voi nua ben phai cua moc
        quickSort(arr, pivotPos + 1, high);
    }
}

int main(void) {
    return 0;
}