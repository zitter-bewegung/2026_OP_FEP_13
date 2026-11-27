#include <stdio.h>
#include <string.h>

#define MAX_WORDS 50
#define MAX_WORD_LEN 100
#define MAX_LINE_LEN 512

void reverse_word(char *str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++) {
        char tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
    }
}

int main(void) {
    char line[MAX_LINE_LEN];
    char words[MAX_WORDS][MAX_WORD_LEN];
    int word_count = 0;

    printf("Enter a proverb (7+ words): ");
    if (fgets(line, sizeof(line), stdin) == NULL) {
        return 1;
    }
    line[strcspn(line, "\r\n")] = '\0';

    char *token = strtok(line, " \t");
    while (token != NULL && word_count < MAX_WORDS) {
        strncpy(words[word_count], token, MAX_WORD_LEN - 1);
        words[word_count][MAX_WORD_LEN - 1] = '\0';
        reverse_word(words[word_count]);
        word_count++;
        token = strtok(NULL, " \t");
    }

    if (word_count < 7) {
        printf("Need at least 7 words, you entered %d\n", word_count);
        return 1;
    }

    for (int i = 0; i < word_count; i++) {
        printf("%s\n", words[i]);
    }
    return 0;
}



2)
#include <stdio.h>
#include <string.h>

#define MAX_PEOPLE 100
#define MAX_LEN 64
#define MAX_LINE_LEN 256
#define MIN_PEOPLE 10

typedef struct {
    char number[MAX_LEN];
    char surname[MAX_LEN];
    char name[MAX_LEN];
} Person;

// безпечне копіювання стрічки
void copy_str(char *dst, const char *src) {
    strncpy(dst, src, MAX_LEN - 1);
    dst[MAX_LEN - 1] = '\0';
}

// кількість ЛІТЕР (а не байтів) у UTF-8 стрічці
size_t utf8_len(const char *s) {
    size_t n = 0;
    for (; *s; s++) {
        if (((unsigned char)*s & 0xC0) != 0x80) n++;
    }
    return n;
}

// порівняння двох людей: спочатку за іменем, потім за прізвищем
int compare_people(const Person *a, const Person *b) {
    int r = strcmp(a->name, b->name);
    if (r != 0) return r;
    return strcmp(a->surname, b->surname);
}

int main(void) {
    Person people[MAX_PEOPLE];
    char line[MAX_LINE_LEN];
    int count = 0;

    printf("Enter the list (Number Surname Name), empty line to finish:\n");
    while (count < MAX_PEOPLE) {
        if (fgets(line, sizeof(line), stdin) == NULL) break;
        line[strcspn(line, "\r\n")] = '\0';
        if (line[0] == '\0') break;

        char *num = strtok(line, " \t");
        char *sur = strtok(NULL, " \t");
        char *nam = strtok(NULL, " \t");
        if (num == NULL || sur == NULL || nam == NULL) {
            printf("Wrong format, try again\n");
            continue;
        }
        copy_str(people[count].number, num);
        copy_str(people[count].surname, sur);
        copy_str(people[count].name, nam);
        count++;
    }

    if (count < MIN_PEOPLE) {
        printf("Need at least %d people, you entered %d\n", MIN_PEOPLE, count);
        return 1;
    }

    // 1) кількість різних імен
    int distinct = 0;
    for (int i = 0; i < count; i++) {
        int seen = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(people[i].name, people[j].name) == 0) {
                seen = 1;
                break;
            }
        }
        if (!seen) distinct++;
    }

    // середня довжина прізвищ
    size_t total = 0;
    for (int i = 0; i < count; i++) {
        total += utf8_len(people[i].surname);
    }
    double average = (double)total / count;

    printf("\nDistinct names: %d\n", distinct);
    printf("Average surname length: %.2f\n", average);

    // 2) сортування (бульбашка)
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (compare_people(&people[j], &people[j + 1]) > 0) {
                Person tmp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = tmp;
            }
        }
    }

    printf("\nSorted list:\n");
    for (int i = 0; i < count; i++) {
        printf("%s %s %s\n", people[i].number, people[i].name, people[i].surname);
    }
    return 0;
}

3)
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN 256
#define MAX_PREFIX_LEN 64
#define MAX_LABEL_LEN 63
#define MIN_LABELS 2
#define MAX_LABELS 3

static const char LETTERS[] =
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const char PREFIX_CHARS[] =
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789._-";
static const char LABEL_CHARS[] =
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-";

// повертає NULL, якщо адреса правильна, інакше текст помилки
const char *check_email(const char *email) {
    // 1) рівно одна '@'
    const char *at = strchr(email, '@');
    if (at == NULL) return "no '@' symbol";
    if (at != strrchr(email, '@')) return "more than one '@' symbol";

    // 2) префікс
    size_t prefix_len = (size_t)(at - email);
    if (prefix_len == 0) return "prefix is empty";
    if (prefix_len > MAX_PREFIX_LEN) return "prefix is too long (max 64)";
    if (strspn(email, PREFIX_CHARS) != prefix_len)
        return "prefix has forbidden characters (allowed: latin letters, digits, . _ -)";
    if (email[0] == '.' || at[-1] == '.')
        return "prefix cannot start or end with a dot";
    if (strstr(email, "..") != NULL) return "two dots in a row";

    // 3) домен: проходимо по частинах, розділених крапками
    const char *start = at + 1;
    if (*start == '\0') return "domain is empty";

    int labels = 0;
    while (1) {
        const char *dot = strchr(start, '.');
        size_t len = (dot != NULL) ? (size_t)(dot - start) : strlen(start);

        if (len == 0) return "empty part in domain";
        if (len > MAX_LABEL_LEN) return "domain part is too long (max 63)";
        if (strspn(start, LABEL_CHARS) != len)
            return "domain has forbidden characters (allowed: latin letters, digits, -)";
        if (start[0] == '-' || start[len - 1] == '-')
            return "domain part cannot start or end with '-'";

        labels++;
        if (dot == NULL) break;      // це була остання частина
        start = dot + 1;             // переходимо до наступної
    }

    if (labels < MIN_LABELS)
        return "domain must have at least 2 parts separated by dots (like gmail.com)";
    if (labels > MAX_LABELS) return "domain has too many parts (max 3)";

    // 4) остання частина (start показує на неї): лише літери, 2+ символи
    size_t last_len = strlen(start);
    if (last_len < 2 || strspn(start, LETTERS) != last_len)
        return "last domain part must be 2+ latin letters";

    return NULL;
}

int main(void) {
    char line[MAX_LINE_LEN];

    printf("Enter e-mail addresses (empty line to finish):\n");
    while (1) {
        printf("> ");
        if (fgets(line, sizeof(line), stdin) == NULL) break;
        line[strcspn(line, "\r\n")] = '\0';
        if (line[0] == '\0') break;

        const char *error = check_email(line);
        if (error == NULL) {
            printf("  VALID\n");
        } else {
            printf("  INVALID: %s\n", error);
        }
    }
    return 0;
}
