#include <stdio.h>

const double N = 7.0;  // Порядковий номер у журналі
const double A = 17.0; // Вік (повних років)


double f(double x) {
    return N * x + A;
}

int main(void) {
    double a = -100.0;
    double b = 100.0;
    double eps = 0.001; 
    double c;


    if (f(a) * f(b) > 0) {
        printf("На заданому інтервалі [-100..100] розв'язку немає.\n");
        return 1;
    }

   
    while ((b - a) >= eps) {
        c = (a + b) / 2.0;

        if (f(c) == 0.0) {
            break;
        } else if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    c = (a + b) / 2.0;
    printf("Наближений розв'язок рівняння %.0f*x + %.0f = 0: x = %.4f\n", N, A, c);

    return 0;
}