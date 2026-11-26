#include <stdio.h>
#include <string.h>
void reverse_word(char str[]) {
  int len = strlen(str);
  char temp;
  for (int i = 0; i < len / 2; i++) {
    temp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = temp;
  }
}
void reverse_sen(char word_list[1024][1024], int count) {
  char temp[1024];

  for (int i = 0; i < count / 2; i++) {
    strcpy(temp, word_list[i]);
    strcpy(word_list[i], word_list[count - i - 1]);
    strcpy(word_list[count - i - 1], temp);
  }
}

int main() {
  char buffer[1024];
  FILE *p = fopen("mfile.txt", "r");
  if (!p) {
    return 1;
  }
  char word_list[1024][1024];
  int count = 0;
  int total_len = 0;
  for (; fgets(buffer, sizeof(buffer), p) != NULL;) {
    printf("%s", buffer);
    buffer[strcspn(buffer, "\r\n")] = '\0';

    reverse_word(buffer);
    snprintf(word_list[count], sizeof(word_list[0]), buffer);
    count++;
    total_len = total_len + strlen(buffer);
  }
  reverse_sen(word_list, count);

  printf("%lf", (double)total_len / count);
  printf("%d", count);
  fclose(p);
  FILE *f = fopen("xfile.txt", "w");
  for (int i = 0; i < count; i++) {
    fputs(word_list[i], f);
    fputc('\n', f);
  }
  fclose(f);
  return 0;
}
