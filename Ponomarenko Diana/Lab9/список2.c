#include <stdio.h>
#include <string.h>

#define MAX 30

int utf8len(const char *s) {
    int n = 0;
    for (; *s; s++) {
        if (((unsigned char)*s & 0xC0) != 0x80) n++;
    }
    return n;
}

int main(void) {
    int n = 0;
    int num[MAX], idx[MAX];
    char surname[MAX][60], name[MAX][60];

    while (n < MAX && scanf("%d %59s %59s", &num[n], surname[n], name[n]) == 3) {
        idx[n] = n;
        n++;
    }

    if (n == 0) {
        printf("Список порожній\n");
        return 1;
    }

    int distinct = 0;
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(name[i], name[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) distinct++;
    }

    int total = 0;
    for (int i = 0; i < n; i++) {
        total += utf8len(surname[i]);
    }

    printf("Кількість студентів: %d\n", n);
    printf("Кількість різних імен: %d\n", distinct);
    printf("Середня довжина прізвищ: %.2f\n", (double)total / n);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(surname[idx[j]], surname[idx[j + 1]]) > 0) {
                int t = idx[j];
                idx[j] = idx[j + 1];
                idx[j + 1] = t;
            }
        }
    }

    printf("\nСписок за алфавітом:\n");
    for (int i = 0; i < n; i++) {
        int k = idx[i];
        printf("%d %s %s\n", num[k], name[k], surname[k]);
    }

    return 0;
}