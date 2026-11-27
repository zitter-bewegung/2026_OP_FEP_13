#include <stdio.h>

int main(void) {
    int i = 1;
    int sum = 0;
    int my_number = 7; 

    while (i <= 100) {
        if (i == my_number || i == 33) {
            i++;      
            continue;
        }
        sum += i;
        i++;
    }

    printf("Сума чисел від 1 до 100 (без %d та 33) = %d\n", my_number, sum);

    return 0;
}