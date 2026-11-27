#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* getElement1D(int arr[], int index) {
    if (index < 0 || index >= 10) {
        return NULL;
    }
    return &arr[index];
}

int main(void) {
    srand(time(NULL));
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");

    int* ptr = getElement1D(arr, 4);
    if (ptr != NULL) {
        printf("Element [4]: %d\n", *ptr);
    } else {
        printf("NULL\n");
    }

    return 0;
}
