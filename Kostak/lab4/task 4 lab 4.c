#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, c, d, x1, x2;

    printf("Введіть a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == 0)
    {
        printf("Це не квадратне рівняння (a = 0)\n");
        return 0;
    }

    d = b * b - 4 * a * c;
    printf("D = %.2f\n", d);

    if (d > 0)
    {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        printf("x1 = %.2f\n", x1);
        printf("x2 = %.2f\n", x2);
    }
    else if (d == 0)
    {
        x1 = -b / (2 * a);
        printf("x = %.2f\n", x1);
    }
    else
    {
        printf("Дійсних коренів немає\n");
    }

    return 0;
}
