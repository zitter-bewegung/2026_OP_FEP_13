#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int* toPoint(int x, int y) {
    int *point = (int*)malloc(2 * sizeof(int));
    if (point != NULL) {
        point[0] = x; 
        point[1] = y; 
    }
    return point;
}

int main(void) {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int x = 5, y = 12;
    int* p = toPoint(x, y);

    if (p != NULL) {
        printf("Створена точка: (%d, %d)\n", p[0], p[1]);
        printf("Адреса в пам'яті: %p\n", (void*)p);

        free(p);
    } else {
        printf("Помилка виділення пам'яті!\n");
    }

    return 0;
}