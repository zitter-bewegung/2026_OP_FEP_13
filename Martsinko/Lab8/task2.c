#include <stdio.h>


int* get_element_1d(int arr[10], int index) {
    if (index >= 0 && index < 10) {
        return &arr[index];
    }
    return NULL;
}

int* get_element_2d(int arr[12][12], int index_1, int index_2) {
    if (index_1 >= 0 && index_1 < 12 && index_2 >= 0 && index_2 < 12) {
        return &arr[index_1][index_2];
    }
    return NULL;
}

int main(){
int arr1D[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int arr2D[12][12] = {0};
    arr2D[5][3] = 42;

    int* element_1d = get_element_1d(arr1D, 5);
    if (element_1d != NULL) {
        printf("адреса: %p\n", (void*)element_1d);
    } else {
        printf("елемент не знайдено!\n");
    }
int find_min_max_sum(const int arr[], int size, int *min, int *max) {
    *min = arr[0];
    *max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }

    return *min + *max;
}''
    int* element_2d = get_element_2d(arr2D, 5, 3);
    if (element_2d != NULL) {
        printf("адреса: %p\n", (void*)element_2d);
    } else {
        printf("елемент не знайдено!\n");
    }

    int* bad_ptr = get_element_1d(arr1D, 99);
    if (bad_ptr == NULL) {
        printf("NULL\n");
    }
    return 0;
}