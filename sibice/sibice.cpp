#include <stdio.h>
#include <math.h>

int main() {
  int n, w, h;
  scanf("%d %d %d", &n, &w, &h);
  int hypotenuse = sqrt(pow(w, 2) + pow(h, 2));
  for (int i = 0; i < n; i ++) {
    int m;
    scanf("%d", &m);
    if (m <= hypotenuse) {
      printf("DA\n");
    } else {
      printf("NE\n");
    }
  }
  return 0;
}