#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char surname[100];
  char name[100];
  double height;
  double weight;
  int age;
  char hair_color[100];
} group;

int compare(const void *a, const void *b) {
  const group *s1 = (const group *)a;
  const group *s2 = (const group *)b;

  if (s1->age < s2->age)
    return 1;
  if (s1->age > s2->age)
    return -1;
  return 0;
}

int main() {
  group g;
  group group_list[30];
  char buffer[2048];
  int count = 0;
  for (int i = 0; fgets(buffer, 2048, stdin) != NULL; i++) {
    sscanf(buffer, "%50s %50s %lf %lf %d %50s", g.surname, g.name, &g.height,
           &g.weight, &g.age, g.hair_color);
    group_list[i] = g;
    count++;
  }

  qsort(group_list, count, sizeof(group), compare);
  for (int j = 0; j < count; j++) {
    printf("%-15s %-12s %6.1lf %6.1lf %4d   %s\n", group_list[j].surname,
           group_list[j].name, group_list[j].height, group_list[j].weight,
           group_list[j].age, group_list[j].hair_color);
  }
  return 0;
}