#include <stdio.h>

int checkDupBruteForce(int numbers[], int size);

int checkDupSubArray(int numbers[], int size);

int main(void) {
    printf("Hello, World!\n");
    return 0;
}

int checkDupBruteForce(int numbers[], int size) {
    //B1: Xét từng phần tử trong mảng
    for (int i = 0; i < size; i++) {
        //B2: So sánh phần tử đó với tất cả phần tử còn lại
        for (int j = i+1; j < size; j++) {
            //B3: Nếu có trùng thi tra ve 1
            if (numbers[i] == numbers[j]) {
                return 1;
            }
        }
    }
    //B4: Neu khong co phan tu trung thi tra ve 0
    return 0;
}

int checkDupSubArray(int numbers[], int size) {
    //B1: Tạo ra mảng phụ để kiểm tra xem phan tu trung lap
    int seenNumbers[1001];
    //B2: Xet tung phan tu
    for (int i = 0; i < size; i++) {
        //B3: kiem tra xem phan tu duoc xet da duoc tim thay chua
        if (seenNumbers[numbers[i]] == 1) {
            //B4: Neu da tung duoc tim thay thi tra ve gia tri 1
            return 1;
        }
    }
    //B5: Neu không có phần tử nào trùng lặp thì tra ve gia tri 0
    return 0;
}