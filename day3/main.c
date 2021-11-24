#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ride_hill(int right, int down, char map[][500], int lines) {
  int trees = 0, cursor = 0, len = strlen(map[0]) - 1;
  for (int i = 0; i < lines; i += down) {
    if (map[i][cursor] == '#')
      trees++;
    cursor = (cursor + right) % len;
  }
  return trees;
}

void part1(char map[][500], int lines) {
  printf("Part 1: %d\n", ride_hill(3, 1, map, lines));
}

void part2(char map[][500], int lines) {
  long trees = 1;
  trees *= ride_hill(1, 1, map, lines);
  trees *= ride_hill(3, 1, map, lines);
  trees *= ride_hill(5, 1, map, lines);
  trees *= ride_hill(7, 1, map, lines);
  trees *= ride_hill(1, 2, map, lines);
  printf("Part 2: %ld\n", trees);
}

int main() {
  char s[50];
  char map[500][500];
  int lines = 0;
  FILE *fp = fopen("input.txt", "r");

  while (fgets(s, sizeof s, fp) != NULL)
    strcpy(map[lines++], s);

  part1(map, lines);
  part2(map, lines);

  return 0;
}
