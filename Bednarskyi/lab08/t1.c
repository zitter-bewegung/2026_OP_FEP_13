#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generateArray10() {
    static int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}

int main(void) {
    srand(time(NULL));
    int* myArr = generateArray10();
    for (int i = 0; i < 10; i++) {
        printf("%d ", myArr[i]);
    }
    printf("\n");
    return 0;
}
