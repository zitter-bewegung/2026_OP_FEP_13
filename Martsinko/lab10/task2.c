#include <stdio.h>
#include <stdlib.h>

int* toPoint(int x, int y) {
    int* arr = malloc(2 * sizeof(int));
    if (arr == NULL){
        return NULL;
    }
    arr[0] = x;
    arr[1] = y;
    return arr;
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    int* point = toPoint(x, y);
    if (point == NULL){
        printf("помилка виділення пам'яті");
        return 1;
    }
    printf("%d %d\n %p\n", point[0], point[1], point);
    free(point);
    return 0;

}