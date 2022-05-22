// Character Stuffing or Byte Stuffing

#include <stdio.h>
#include <string.h>
int main() {
  int j, l, m, c, k;
  char a[50], b[50];
  printf("Enter the string:");
  scanf("%s", a);
  strcpy(b, "DLESTX");
  m = strlen(a);
  for (j = 0; j < m;) {
    if (a[j] == 'd') {
      if (a[j + 1] == 'l') {
        if (a[j + 2] == 'e') {
          c = j + 2;
          for (l = 0; l < 3; l++) {
            for (k = m; k > c; k--) {
              a[k] = a[k - 1];
            }
            m++;
            a[m] = ' ';
            c += 1;
          }
          a[j + 3] = 'd';
          a[j + 4] = 'l';
          a[j + 5] = 'e';
          a[m] = ' ';
          j += 5;
        }
      }
    }
    j++;
  }
  strcat(b, a);
  strcat(b, "DLEETX");
  printf("\n%s", b);
  printf("\nReceiver side:");
  m = strlen(a);
  for (j = 0; j < m;) {
    if (a[j] == 'd') {
      if (a[j + 1] == 'l') {
        if (a[j + 2] == 'e') {
          c = j;
          for (l = 0; l < 3; l++) {
            for (k = c; k < m; k++)
              a[k] = a[k + 1];
          }
          c++;
        }
        j = c;
      }
    }
    j++;
  }
  printf("\n%s", a);
}

// Output 1:
// ------------
// Enter the string:ece
// DLESTXeceDLEETX
// Receiver side:
// ece

// Output 2:
// ------------
// Enter the string:abcdledef
// DLESTXabcdledledef DLEETX
// Receiver side:
// abcdledef