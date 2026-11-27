#include <stdio.h>
#include <windows.h>

int* find_element_1d(int mas[10], int idx) {
    if (idx >= 0 && idx < 10) {
        return &mas[idx];
    }
    return NULL;
}

int* find_element_2d(int mas[12][12], int row, int col) {
    if (row >= 0 && row < 12 && col >= 0 && col < 12) {
        return &mas[row][col];
    }
    return NULL;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int mas1D[10] = {5, 15, 25, 35, 45, 55, 65, 75, 85, 95};
    int mas2D[12][12] = {0};
    mas2D[4][7] = 55;

    int* ptr_1d = find_element_1d(mas1D, 4);
    if (ptr_1d != NULL) {
        printf("адреса: %p\n", (void*)ptr_1d);
    } else {
        printf("елемент не знайдено!\n");
    }

    int* ptr_2d = find_element_2d(mas2D, 4, 7);
    if (ptr_2d != NULL) {
        printf("адреса: %p\n", (void*)ptr_2d);
    } else {
        printf("елемент не знайдено!\n");
    }

    int* invalid_ptr = find_element_1d(mas1D, 88);
    if (invalid_ptr == NULL) {
        printf("NULL\n");
    }

    return 0;
}