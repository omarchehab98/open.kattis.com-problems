#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14159265

int main() {
  int opposite, theta;

  cin >> opposite >> theta;
  cout << ceil(opposite / sin(theta * PI / 180));
}
