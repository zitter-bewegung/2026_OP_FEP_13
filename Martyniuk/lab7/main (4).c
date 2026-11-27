#include <stdio.h>


int recursiveSum(int n) {
    if (n > 100) {
        return 0;
    }
    if (n == 100) {
        return 100; 
    }
    return n + recursiveSum(n + 1); 
}

int main(void) {
    int N = 7;

    int result = recursiveSum(N);
    printf("Сума чисел від %d до 100 дорівнює: %d\n", N, result);

    return 0;
}