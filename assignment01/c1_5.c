#include <stdio.h>

int main() {
  double x;
  int y;

  scanf("%lf %d", &x, &y);

  for (int i = 0; i < y; i++) {
    x += 1;
  }

  if (x >= 10) {
    printf("10‚æ‚è‘å‚«‚¢\n");
  }
  else {
    printf("10–¢–ž\n");
  }
  
  return 0;
}
