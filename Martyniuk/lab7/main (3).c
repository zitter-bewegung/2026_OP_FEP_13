#include <stdio.h>
#include <stdbool.h>


bool isPrime(int n) {
    if (n <= 1) {
        return false; 
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false; 
        }
    }
    return true; 
}

int main(void) {
    int number;
    printf("Введіть ціле число: ");
    scanf("%d", &number);

    if (isPrime(number)) {
        printf("Число %d є простим.\n", number);
    } else {
        printf("Число %d НЕ є простим.\n", number);
    }

    return 0;
}