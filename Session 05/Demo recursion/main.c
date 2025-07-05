#include <stdio.h>

//In tat ca cac gia tri tu 1 - n
void print1ToN(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
}
void print1ToNRecursion(int n) {
    if (n == 1) {
        printf("%d ", n);
        return;
    }
    printf("%d ", n);
    print1ToNRecursion(n - 1);
}
int sum1ToN(int n) {
    if (n == 1) {
        return 1;
    }
    return sum1ToN(n-1) + n;
}
int main(void) {

    int sum = sum1ToN(10);
    printf("sum = %d\n", sum);
    // print1ToNRecursion(5);
    return 0;
}