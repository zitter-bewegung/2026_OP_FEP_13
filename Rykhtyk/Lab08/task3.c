#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void create_random_arr(int mas[], int len) {
    for (int i = 0; i < len; i++) {
        mas[i] = rand() % 100;
    }
}

int calc_min_max_sum(const int mas[], int len, int *min_el, int *max_el) {
    *min_el = mas[0];
    *max_el = mas[0];
    for (int i = 1; i < len; i++) {
        if (mas[i] < *min_el) {
            *min_el = mas[i];
        }
        if (mas[i] > *max_el) {
            *max_el = mas[i];
        }
    }
    return *min_el + *max_el;
}

int main(void) {
    srand(time(NULL));
    int numbers[20];
    create_random_arr(numbers, 20);

    int min_el, max_el;
    int result = calc_min_max_sum(numbers, 20, &min_el, &max_el);
    printf("Min: %d\n", min_el);
    printf("Max: %d\n", max_el);
    printf("Sum: %d\n", result);

    return 0;
}