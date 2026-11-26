#include <stdio.h>

double add(double a, double b) {
    return a + b;
}
double sub(double a, double b) {
    return a - b;
}
double mul(double a, double b) {
    return a * b;
}
double div(double a, double b) {
    if (b == 0) {
        printf("error: division by zero\n");
        return 0;
    }
    return a / b;
}
int main() {
    double a, b;
    char op;
    double (*ops[4])(double, double) = {add, sub, mul, div};
    scanf("%lf %c %lf", &a, &op, &b);
    switch(op){
        case '+':
            printf("%lf\n", ops[0](a, b));
            break;
        case '-':
            printf("%lf\n", ops[1](a, b));
            break;
        case '*':
            printf("%lf\n", ops[2](a, b));
            break;
        case '/':
            printf("%lf\n", ops[3](a, b));
            break;
        default:
            printf("error: unknown operator\n");
            break;
    }
    return 0;
}