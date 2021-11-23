#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int start;
  int end;
  char letter;
  char rest[25];
} password;

void part1(password *p, int lines) {
  int valid = 0;
  for (int i = 0; i < lines; i++) {
    int count = 0;
    for (int j = 0; j < strlen(p[i].rest); j++)
      if (p[i].rest[j] == p[i].letter)
        count++;
    if (count >= p[i].start && count <= p[i].end)
      valid++;
  }
  printf("Part 1: %d\n", valid);
}

void part2(password *p, int lines) {
  int valid = 0;
  for (int i = 0; i < lines; i++) {
    char letter = p[i].letter;
    int start = p[i].start - 1, end = p[i].end - 1;
    if (p[i].rest[start] == letter ^ p[i].rest[end] == letter)
      valid++;
  }
  printf("Part 2: %d\n", valid);
}

int main() {
  char s[50];
  int lines = 0;
  FILE *fp = fopen("input.txt", "r");

  password p[1000];
  while (fgets(s, sizeof s, fp) != NULL) {
    password temp;
    sscanf(s, "%d-%d %c: %s\n", &temp.start, &temp.end, &temp.letter, temp.rest);
    p[lines++] = temp;
  }

  part1(p, lines);
  part2(p, lines);

  return 0;
}
