#include <stdio.h>

typedef struct {
  char brand[32];
  double screen_size;
  char resolution[16];
  char cpu[32];
  int ram_gb;
  char storage_type[16];
  int storage_gb;
  char gpu[32];
  int battery_wh;
  double price;
} Laptop;

void print_table(const Laptop *list, int count) {
  printf("%-3s | %-10s | %-6s | %-11s | %-18s | %-5s | %-7s | %-6s | %-16s | "
         "%-7s \n",
         "Виробник", "Екран", "Роздільність", "Процесор", "ОЗП", "Диск",
         "Обсяг", "Відеокарта", "батарея", "ціна");
  for (int i = 0; i < count; i++) {
    printf("%-3d | %-10s | %5.1f\" | %-11s | %-18s | %3dГБ | %-7s | %4dГБ | "
           "%-16s | %4d | %7.0f\n",
           i + 1, list[i].brand, list[i].screen_size, list[i].resolution,
           list[i].cpu, list[i].ram_gb, list[i].storage_type,
           list[i].storage_gb, list[i].gpu, list[i].battery_wh, list[i].price);
  }
}

void print_details(const Laptop *l, int index) {
  printf("\n=== Обраний ноутбук #%d ===\n", index);
  printf("Виробник:              %s\n", l->brand);
  printf("Розмір дисплея:        %.1f\"\n", l->screen_size);
  printf("Роздільна здатність:   %s\n", l->resolution);
  printf("Тип процесора:         %s\n", l->cpu);
  printf("Оперативна пам'ять:    %d ГБ\n", l->ram_gb);
  printf("Тип накопичувача:      %s\n", l->storage_type);
  printf("Обсяг диска:           %d ГБ\n", l->storage_gb);
  printf("Тип відеокарти:        %s\n", l->gpu);
  printf("батарея:               %d\n", l->battery_wh);
  printf("Ціна:                  %.2f\n", l->price);
}

int main(void) {
  Laptop laptops[] = {{"Lenovo", 15.6, "1920x1080", "Ryzen 7 7840HS", 16,
                       "NVMe", 512, "RTX 4060", 80, 1250.0},
                      {"ASUS", 14.0, "2880x1800", "Core Ultra 7 155H", 32,
                       "NVMe", 1024, "Intel Arc", 75, 1400.0},
                      {"Apple", 14.2, "3024x1964", "Apple M3 Pro", 18, "SSD",
                       512, "M3 Pro 14-core", 70, 1999.0},
                      {"Dell", 13.4, "1920x1200", "Core i7-1360P", 16, "NVMe",
                       512, "Intel Iris Xe", 55, 1300.0},
                      {"Acer", 15.6, "1920x1080", "Core i5-12450H", 16, "NVMe",
                       512, "RTX 3050", 57, 780.0},
                      {"HP", 16.1, "2560x1440", "Ryzen 9 7940HS", 32, "NVMe",
                       1024, "RTX 4070", 83, 1650.0},
                      {"MSI", 17.3, "2560x1440", "Core i9-13980HX", 64, "NVMe",
                       2048, "RTX 4080", 99, 2800.0}};

  int count = sizeof(laptops) / sizeof(laptops[0]);
  print_table(laptops, count);

  int choice = 0;
  printf("\nВведіть номер ноутбука (1-%d): ", count);
  if (scanf("%d", &choice) != 1 || choice < 1 || choice > count) {
    return 1;
  }

  print_details(&laptops[choice - 1], choice);
  return 0;
}