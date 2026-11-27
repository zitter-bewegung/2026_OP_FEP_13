#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>

int my_strlen(const char* str) {
	int count = 0;
	const char* p = str;
	while (*p != '\0' && *p != '\n' && *p != '\r') {
		if ((*p & 0xC0) != 0x80) {
			count++;
		}
		p++;
	}
	return count;
}

int main(void) {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	char str[100];
	printf("Введіть рядок: ");

	fgets(str, sizeof(str), stdin);

	printf("Довжина рядка: %d\n", my_strlen(str));

	return 0;
}