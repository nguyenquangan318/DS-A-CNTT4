#include <stdio.h>

// Xay dung cau truc sinh vien
struct Student {
    int id;
    char name[20];
    int age;
};

// Xay dung ham tim kiem theo id
int linearSearch(struct Student students[], int searchId, int size) {
    for (int i = 0; i < size; i++) {
        if (students[i].id == searchId) {
            return i;
        }
    }
    return -1;
}

int binarySearch(struct Student students[], int searchId, int size) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (searchId == students[mid].id) {
            return mid;
        }
        if (searchId > students[mid].id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Goi ham va in ket qua
int main(void) {
    // Nhap thong tin cho tung sinh vien trong mang
    int numbers[5] = {1, 2, 3, 4, 5};
    struct Student students[5] = {
        {1, "Alice", 20},
        {2, "Bob", 21}
    };

    // for (int i = 0; i < 2; i++) {
    //     printf("%d, %s, %d\n", students[i].id, students[i].name, students[i].age);
    // }

    int searchIndex = binarySearch(students, 7, 2);
    if (searchIndex == -1) {
        printf("Not Found\n");
        return 0;
    }
    printf("%d, %s, %d\n", students[searchIndex].id, students[searchIndex].name, students[searchIndex].age);
    return 0;
}
