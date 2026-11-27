#include <stdio.h>

int main(void) {
    int n;

   
    do {
        printf("Введіть ціле число N (від 7 до 12): ");
        scanf("%d", &n);
        if (n < 7 || n > 12) {
            printf("Помилка! Число має бути в межах [7; 12]. Спробуйте ще раз.\n");
        }
    } while (n < 7 || n > 12);

    double num, sum = 0.0, min, max;

    for (int i = 0; i < n; i++) {
        printf("Введіть дійсне число #%d: ", i + 1);
        scanf("%lf", &num);

        sum += num;

        
        if (i == 0) {
            min = num;
            max = num;
        } else {
            if (num < min) min = num;
            if (num > max) max = num;
        }
    }

    double average = sum / n;

    printf("\nРезультати:\n");
    printf("Сума: %.2lf\n", sum);
    printf("Середнє арифметичне: %.2lf\n", average);
    printf("Мінімальне значення: %.2lf\n", min);
    printf("Максимальне значення: %.2lf\n", max);

    return 0;
}