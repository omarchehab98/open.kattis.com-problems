#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main() {
  int n;
  double w, g, h, r;
  cin >> n;
  while(n--) {
    cin >> w >> g>>h>>r;
    double minv = sqrt(w*w + fabs(g-h) * fabs(g-h));
    double maxv = sqrt((g+h-2*r) * (g+h-2*r) + w*w);
    printf("%.8lf %.8lf\n", minv, maxv);
  }
  return 0;
}