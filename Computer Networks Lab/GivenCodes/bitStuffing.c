// Bit Stuffing

#include "stdio.h"
int main() {
  int i = 0, count = 0;
  char a[100];
  printf("enter the bits : ");
  scanf("%s", a);
  printf("\nAfter bit stuffing \n");
  printf("01111110  ");
  for (i = 0; a[i]; i++) {
    if (a[i] == '1')
      count++;
    else
      count = 0;
    printf("%c", a[i]);
    if (count == 5) {
      printf("0");
      count = 0;
    }
  }
  printf("  01111110");
  return 1;
}

// Output:
// ----------
// enter the bits : 0100111111001
// After bit stuffing
// 01111110  01001111101001  01111110