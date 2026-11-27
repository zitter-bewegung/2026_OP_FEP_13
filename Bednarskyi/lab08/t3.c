#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void findMinMaxSum20() {
    int arr[20];
    for (int i = 0; i < 20; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");

    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < 20; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    printf("Sum: %d\n", min + max);
}

int main(void) {
    srand(time(NULL));
    findMinMaxSum20();
    return 0;
}
