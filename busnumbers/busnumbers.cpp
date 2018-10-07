#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int numberOfBusses, i, j;
  cin >> numberOfBusses;
  int busses[numberOfBusses];

  for (i = 0; i < numberOfBusses; i++) {
    cin >> busses[i];
  }
  for (i = 0; i < numberOfBusses; i++) {
    int smallest = i;
    int swap;
    
    for (j = i + 1; j < numberOfBusses; j++) {
      if (busses[j] < busses[smallest]) {
        smallest = j;
      }
    }

    swap = busses[i];
    busses[i] = busses[smallest];
    busses[smallest] = swap;
  }

  int range = 0;
  cout << busses[0];
  for (i = 1; i < numberOfBusses; i++) {
    if (busses[i - 1] + 1 == busses[i]) {
      range++;
    } else {
      if (range > 1) {
        cout << "-" << busses[i - 1];
      } else if (range == 1) {
        cout << " " << busses[i - 1];
      }
      range = 0;
      cout << " " << busses[i];
    }
  }
  if (range > 1) {
    cout << "-" << busses[i - 1];
  } else if (range == 1) {
    cout << " " << busses[i - 1];
  }
}
