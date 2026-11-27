#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* getElement2D(int matr[12][12], int row, int col) {
    if (row < 0 || row >= 12 || col < 0 || col >= 12) {
        return NULL;
    }
    return &matr[row][col];
}

int main(void) {
    srand(time(NULL));
    int matr[12][12];
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            matr[i][j] = rand() % 100;
        }
    }

    int* ptr = getElement2D(matr, 5, 8);
    if (ptr != NULL) {
        printf("Element [5][8]: %d\n", *ptr);
    } else {
        printf("NULL\n");
    }

    return 0;
}
