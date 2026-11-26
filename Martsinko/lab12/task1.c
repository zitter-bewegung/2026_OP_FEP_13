#include <stdio.h>

int main(void) {
  FILE *file = fopen("mfile.txt", "w");
  if (!file) {
    return 1;
  }

  char buffer[1024];
  int lines = 0;

  while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
    fputs(buffer, file);
    lines++;
  }

  fclose(file);

  if (lines < 10) {
    printf("мало рядків %d", lines);
  }

  return 0;
}