#include <stdio.h>
#include <ctype.h>

int main(void) {
    char str[256];
    int vowels = 0, consonants = 0;

    printf("Введіть речення англійською мовою: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower((unsigned char)str[i]); 

        if (ch >= 'a' && ch <= 'z') { 
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    printf("Кількість голосних: %d\n", vowels);
    printf("Кількість приголосних: %d\n", consonants);

    return 0;
}