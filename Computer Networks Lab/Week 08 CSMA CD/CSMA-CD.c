//  CSMA With Collision Detection

// Compile with gcc <file_name>.c -o <file_name> -pthread

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
int x = 0;
void capture() { exit(0); }
int get() { return x; }
void put() { x++; }

void node(char *p) {
  int name;
  int seq1, seq2, i = 0;
  long int t;
  struct timeval tv;
  struct timezone tz;
  name = atoi(p);
  while (1) {
    seq1 = get();
    seq2 = get();
    if (seq1 == seq2) {
      put();
      seq1 = get();
      printf("station %d transmitting frame %d\n", name, ++i);
      sleep(3);
      seq2 = get();
      if (seq1 != seq2) {
        printf("station %d collision occurred %d \n", name, i--);
        sleep(3);
      } else {
        printf("%d station %d complete\n", name, i);
      }
    }
    sleep(3);
  }
}

int main() {
  pthread_t t1, t2, t3, t4, t5;
  pthread_create(&t1, 0, (void *)node, "1");
  pthread_create(&t2, 0, (void *)node, "2");
  pthread_create(&t3, 0, (void *)node, "3");
  pthread_create(&t4, 0, (void *)node, "4");
  pthread_create(&t5, 0, (void *)node, "5");
  while (1)
    ;
}