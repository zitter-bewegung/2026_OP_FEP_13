#include <stdio.h>

void print_bin(unsigned char x)
{
    for (int i = 7; i >= 0; i--)
        printf("%d", (x >> i) & 1);
}

int main(void)
{
    int a = 12, b = 5;
    unsigned char ua = a, ub = b;

    printf("a = %d, b = %d\n\n", a, b);

    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);
    printf("a %% b = %d\n", a % b);
    printf("-a = %d\n", -a);
    printf("a++ = %d\n", a++);
    printf("++a = %d\n", ++a);
    printf("a-- = %d\n", a--);
    printf("--a = %d\n\n", --a);

    printf("a > b: %d\n", a > b);
    printf("a >= b: %d\n", a >= b);
    printf("a < b: %d\n", a < b);
    printf("a <= b: %d\n", a <= b);
    printf("a == b: %d\n", a == b);
    printf("a != b: %d\n\n", a != b);

    printf("a && b: %d\n", a && b);
    printf("a || b: %d\n", a || b);
    printf("!a: %d\n\n", !a);

    printf("a = ");
    print_bin(ua);
    printf("\nb = ");
    print_bin(ub);
    printf("\n\na & b  = ");
    print_bin(ua & ub);
    printf("\na | b  = ");
    print_bin(ua | ub);
    printf("\na ^ b  = ");
    print_bin(ua ^ ub);
    printf("\n~a     = ");
    print_bin(~ua);
    printf("\na << 1 = ");
    print_bin(ua << 1);
    printf("\na >> 1 = ");
    print_bin(ua >> 1);
    printf("\n");

    return 0;
}
