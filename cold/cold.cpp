#include <iostream>
#include <cmath>

using namespace std;

int main () {
  int temperaturesUnderZero = 0, numberOfTemperatures, i;
  cin >> numberOfTemperatures;
  for (i = 0; i < numberOfTemperatures; i++) {
    long temperature;
    cin >> temperature;
    if (temperature < 0) {
      temperaturesUnderZero++;
    }
  }
  cout << temperaturesUnderZero;
}
