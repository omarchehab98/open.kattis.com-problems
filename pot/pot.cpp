#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int n, total = 0;
  cin >> n;
  while (n-- > 0) {
    string p;
    cin >> p;
    int number, power;
    number = stoi(p.substr(0, p.size() - 1));
    power = stoi(p.substr(p.size() - 1, 1));
    total += pow(number,power);
  }
  cout << total;
}
