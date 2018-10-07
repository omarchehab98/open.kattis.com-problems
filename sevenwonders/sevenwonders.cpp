#include <bits/stdc++.h>

using namespace std;

int main() {
  string in;
  cin >> in;
  long out = 0;
  int t = 0, c = 0, g = 0;
  for (int i = 0; i < in.size(); i++) {
    switch (in[i]) {
      case 'T':
        t++;
        break;
      case 'C':
        c++;
        break;
      case 'G':
        g++;
        break;
    }
  }
  out = pow(t,2) + pow(c,2) + pow(g,2) + (min(min(t,c),g) * 7);
  cout << out << endl;
  return 0;
}
