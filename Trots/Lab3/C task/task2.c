#include <stdio.h>

int main() {
    char student_name[50];
    char student_email[50];
    char fav_hobby[30];

    // Введення даних з клавіатури
    printf("Введіть Прізвище та Ініціали: ");
    scanf(" %49[^\n]", student_name);

    printf("Введіть Email: ");
    scanf("%49s", student_email);

    printf("Введіть Улюблене хобі: ");
    scanf(" %29[^\n]", fav_hobby);

    printf("\n");

    // Шапка таблиці
    printf("%-4s %-25s %-30s %+10s\n", 
           "№", "Прізвище, Ініціали", "Ел. пошта", "Хобі");
    printf("---------------------------------------------------------------------------\n");

    // Виведення даних у вигляді форматованого рядка
    printf("%-4d %-25s %-30s %-20s\n", 
           1, student_name, student_email, fav_hobby);

    return 0;
}