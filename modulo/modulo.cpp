#include <iostream>

using namespace std;

int main() {
  int n;
  int t = 0;
  bool numbers[42];
  for (n = 0; n < 42; n++) {
    numbers[n] = false;
  }
  for (n = 0; n < 10; n++) {
    int number;
    cin >> number;
    if (!numbers[number % 42]) {
      t++;
      numbers[number % 42] = true;
    }
  }
  cout << t;
}
