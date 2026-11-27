#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void fill_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

int main(void) {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int numbers[10];
    srand(time(NULL));

    fill_array(numbers, 10);

    printf("Масив з 10 чисел:\n[ ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("]\n");

    return 0;
}