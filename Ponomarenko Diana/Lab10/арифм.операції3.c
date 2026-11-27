#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

double add(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }
double mul(double a, double b) { return a * b; }
double div_func(double a, double b) {
    if (b != 0) return a / b;
    printf("Помилка: ділення на нуль!\n");
    return 0.0;
}

int main(void) {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    double (*operations[4])(double, double) = { add, sub, mul, div_func };

    double a, b;
    char op;

    printf("Введіть вираз: ");
    if (scanf("%lf %c %lf", &a, &op, &b) == 3) {
        double result = 0;
        int valid = 1;

        switch (op) {
        case '+': result = operations[0](a, b); break;
        case '-': result = operations[1](a, b); break;
        case '*': result = operations[2](a, b); break;
        case '/': result = operations[3](a, b); break;
        default:
            printf("Невідомий оператор!\n");
            valid = 0;
        }

        if (valid) {
            printf("Результат: %.2f\n", result);
        }
    } else {
        printf("Помилка введення даних.\n");
    }

    return 0;
}