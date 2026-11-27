#include <stdio.h>
#include <string.h>

#define MAX_WORDS 50

void reverseRange(char *s, int a, int b) {
    while (a < b) {
        char temp = s[a];
        s[a] = s[b];
        s[b] = temp;
        a++;
        b--;
    }
}

void reverse(char *s) {
    int len = (int)strlen(s);
    reverseRange(s, 0, len - 1);

    int i = 0;
    while (i < len) {
        if (((unsigned char)s[i] & 0xC0) == 0x80) {
            int j = i;
            while (j < len && ((unsigned char)s[j] & 0xC0) == 0x80) j++;
            reverseRange(s, i, j);
            i = j + 1;
        } else {
            i++;
        }
    }
}

int main(void) {
    char str[300];
    char *words[MAX_WORDS];
    int count = 0;

    printf("Введіть прислів’я (7+ слів):\n");
    if (scanf(" %299[^\n]", str) != 1) {
        printf("Помилка введення\n");
        return 1;
    }

    char *token = strtok(str, " ,.!?;:");
    while (token != NULL && count < MAX_WORDS) {
        words[count] = token;
        count++;
        token = strtok(NULL, " ,.!?;:");
    }

    if (count < 7) {
        printf("\nУвага: у прислів’ї менше 7 слів\n");
    }

    printf("\nСлова з перевернутими символами:\n");
    for (int i = 0; i < count; i++) {
        reverse(words[i]);
        printf("%s\n", words[i]);
    }

    return 0;
}