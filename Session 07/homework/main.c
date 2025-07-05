#include <stdio.h>

void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {
    //Xay dung dieu kien dung
    if (n == 0) {
        return;
    }
    //Giai quyen bai toan con voi n - 1 dia tu thap bat dau
    towerOfHanoi(n-1, fromRod, auxRod, toRod);
    //Chuyen dia lon nhat tu thap bat dau den thap ket thuc
    printf("Chuyen dia %d tu thap %c sang thap %c\n", n, fromRod, toRod);
    //Giai quyet bai toan con voi n - 1 dia da duoc chuyen
    towerOfHanoi(n-1, auxRod, toRod, fromRod);
}

int main(void) {
    towerOfHanoi(3, 'A', 'C', 'B');
    return 0;
}