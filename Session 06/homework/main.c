#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Bai 2
int sumNumber(int n) {
    if (n==1) {
        return 1;
    }
    return n+ sumNumber(n-1);
}

//Bai 3
int factorial(int n) {
    if (n==1) {
        return 1;
    }
    return n*factorial(n-1);
}

//Bai 1
int toNumber(int n) {
    if (n==0) return;
    toNumber(n-1);
    printf("%d ",n);
}

//Bai4
int sum(int first,int second) {
    if (first > second) {
        return 0;
    }
    return first + sum(first + 1, second);
}

//Bai 6
int sumArray(int arr[], int n) {
    if (n==0) {
        return 0;
    }
    return arr[n-1]+sumArray(arr,n-1);
}

//Bai 5
int doiXung(str[], int left, int right) {
    if (left >= right) {
        return 1;
    }
    if (str[left] != str[right]) {
        return 0;
    }
    return doiXung(str, left + 1, right-1);
}

//Bai 9
int countPath( int row, int col, int i ,int j) {
    //Dieu kien dung khi vuot qua gioi han mang
    if (i >= row || j >= col) {
        return 0;
    }
    //Dieu kien dung khi den dich
    if (i == row - 1 && j == col - 1) {
        return 1;
    }
    //Giai quyet bai toan con voi o ben phai va o ben duoi
    return countPath(row, col, i , j+1) + countPath(row, col, i+1, j);
}

int main() {
    int n;
    int check;
    char str[100];
    printf("Moi ban nhap chuoi: \n");
    fgets(str,100,stdin);
    str[strlen(str)-1] = '\0';
    check = doiXung(str, 0, strlen(str) - 1);
    if (check == 1) {
        printf("Day la chuoi doi xung\n");
    } else {
        printf("Ko phai chuoi doi xung\n");
    }
    return 0;
}