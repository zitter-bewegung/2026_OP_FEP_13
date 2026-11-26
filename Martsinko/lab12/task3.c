#include <stdio.h>
#include <string.h>

int has_valid_ext(const char *filename) {
  const char *ext = strrchr(filename, '.');
  if (!ext) {
    return 0;
  }
  return strcmp(ext, ".pdf") == 0 || strcmp(ext, ".jpg") == 0 ||
         strcmp(ext, ".PDF") == 0 || strcmp(ext, ".JPG") == 0;
}

int main(void) {
  char src_name[256];
  char dst_name[256];
  scanf("%255s", src_name);
  if (!has_valid_ext(src_name)) {
    return 1;
  }

  scanf("%255s", dst_name);

  FILE *src = fopen(src_name, "rb");
  if (!src) {
    return 1;
  }

  FILE *dst = fopen(dst_name, "wb");
  if (!dst) {
    fclose(src);
    return 1;
  }

  unsigned char buffer[1024 * 1024 * 2];
  size_t bytes_read;

  while ((bytes_read = fread(buffer, 1, sizeof(buffer), src)) > 0) {
    if (fwrite(buffer, 1, bytes_read, dst) != bytes_read) {
      fclose(src);
      fclose(dst);
      return 1;
    }
  }

  fclose(src);
  fclose(dst);
  return 0;
}