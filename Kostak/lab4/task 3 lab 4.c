#include <stdio.h>

int main(void)
{
    int x;
    int *p = &x;

    printf("Введіть число: ");
    scanf("%d", &x);

    printf("Адреса змінної: %p\n", (void *)p);
    printf("Значення через вказівник: %d\n", *p);

    return 0;
}
