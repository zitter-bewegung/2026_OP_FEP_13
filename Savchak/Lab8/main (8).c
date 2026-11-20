/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
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

int main(void) {
    // Змінила числа в одновимірному масиві
    int arr1D[10] = {5, 15, 25, 35, 45, 55, 65, 75, 85, 95};
    
    int arr2D[12][12] = {0};
    // Змінила число в двовимірному масиві
    arr2D[4][6] = 77;

int* element_1d = get_element_1d(arr1D, 4);
if (element_1d != NULL) {
    printf("адреса (1D): %p\n", (void*)element_1d);
} else {
    printf("елемент не знайдено\n");
}

int* element_2d = get_element_2d(arr2D, 4, 6);
if (element_2d != NULL) {
    printf("адреса (2D): %p\n", (void*)element_2d);
} else {
    printf("елемент не знайдено\n");
}

int* bad_ptr = get_element_1d(arr1D, 99);
if (bad_ptr == NULL) {
    printf("NULL\n");
}

return 0;
}
