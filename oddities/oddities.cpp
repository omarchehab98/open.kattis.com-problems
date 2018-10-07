#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int n;
  cin >> n;
  while (n-- > 0) {
    int number;
    cin >> number;
    cout << number << " is " << (abs(number) % 2 == 0 ? "even" : "odd") << endl;
  }
}
