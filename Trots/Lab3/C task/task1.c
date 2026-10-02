#include <stdio.h>

int main() {
    int item_count = 11;
    printf("=== Ціле число ===\n");
    printf("2-ва система  (%%b): %b\n", item_count);
    printf("8-ва система  (%%o): %o\n", item_count);
    printf("10-ва система (%%d): %d\n", item_count);
    printf("16-ва система (%%x): %x\n\n", item_count);

    double temperature = 36.654;
    printf("=== Дійсне число ===\n");
    printf("Стандартний вивід: %f\n", temperature);
    printf("Експоненційний:    %e\n", temperature);
    printf("Гнучкий (%%g):    %g\n\n", temperature);

    char grade = 'B';
    char course_name[] = "Hello World!";
    int *ptr_count = &item_count;

    printf("=== Символ, стрічка, вказівник ===\n");
    printf("Символ:    %c\n", grade);
    printf("Стрічка:   %s\n", course_name);
    printf("Вказівник: %p\n", ptr_count);

    return 0;
}