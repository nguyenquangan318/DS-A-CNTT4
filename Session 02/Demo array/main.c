#include <stdio.h>
#include <stdlib.h>
//cap phat dong
int main(void) {
    // demo malloc
    // int numbers[5];
    // int *numbers = (int *)malloc( 5  *  sizeof( int ) );

    //demo calloc
    // int numbers[10]= {0};
    int *numbers = (int *)calloc(10 , sizeof(int));

    //demo realloc
    numbers = (int *)realloc(numbers,5*sizeof(int));
    printf("Hello, World!\n");
    return 0;
}