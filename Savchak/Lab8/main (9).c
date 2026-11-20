/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_random_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
         arr[i] = rand() % 100;
    }
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
}

int main(void) {
    srand(time(NULL));
    
    int array[20];
    fill_random_array(array, 20);

    int min, max;
    int sum = find_min_max_sum(array, 20, &min, &max);

    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    printf("Sum: %d\n", sum);

return 0;
}