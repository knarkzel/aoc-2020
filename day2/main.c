#include <stdio.h>
#include <stdlib.h>

void part1(int lines, int n[512]) {
  for (int i = 0; i < lines; i++)
    for (int j = 0; j < lines; j++)
      if (n[i] + n[j] == 2020 && i != j) {
        printf("Part 1: %d\n", n[i] * n[j]);
        return;
      }
}

void part2(int lines, int n[512]) {
  for (int i = 0; i < lines; i++)
    for (int j = 0; j < lines; j++)
      for (int k = 0; k < lines; k++)
        if (n[i] + n[j] + n[k] == 2020 && i != j != k) {
          printf("Part 2: %d\n", n[i] * n[j] * n[k]);
          return;
        }
}

int main() {
  int lines = 0;
  char s[4096];
  int n[512] = { 0 };
  FILE *fp = fopen("input.txt", "r");

  while (fgets(s, sizeof s, fp) != NULL) 
    n[lines++] = atoi(s);

  part1(lines, n);
  part2(lines, n);

  return 0;
}
