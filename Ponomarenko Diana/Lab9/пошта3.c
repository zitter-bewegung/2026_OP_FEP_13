#include <stdio.h>
#include <string.h>

int isGood(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')  ||(c >= '0' && c <= '9');
}

int checkEmail(const char *s) {
    const char *at = strchr(s, '@');
    if (at == NULL || at == s) return 0;    
    if (strchr(at + 1, '@') != NULL) return 0; 

    for (const char *p = s; p < at; p++) {
        if (!isGood(*p) && *p != '.' && *p != '_' && *p != '-') return 0;
    }

    int parts = 0, len = 0;
    for (const char *p = at + 1; ; p++) {
        if (*p == '.' || *p == '\0') {
            if (len == 0) return 0;
            parts++;
            len = 0;
            if (*p == '\0') break;
        } else if (isGood(*p) || *p == '-') {
            len++;
        } else {
            return 0;
        }
    }
    return parts == 2 || parts == 3;
}

int main(void) {
    char email[100];

    printf("Вводьте адреси (для виходу введіть 0):\n");
    while (scanf("%99s", email) == 1) {
        if (strcmp(email, "0") == 0) break;
        if (checkEmail(email)) printf("Адреса правильна\n");
        else printf("Адреса неправильна\n");
    }

    return 0;
}