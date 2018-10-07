#include <iostream>

using namespace std;

int main() {
  int numberOfLogs;
  while (true) {
    cin >> numberOfLogs;
    if (numberOfLogs == -1) {
      break;
    }
    int total = 0;
    int previousTime = 0;
    for (int n = 0; n < numberOfLogs; n++) {
      int speed, time;
      cin >> speed >> time;
      int prev = time;
      time -= previousTime;
      previousTime = prev;
      total += speed * time;
    }
    cout << total << " miles" << endl;
  }
}
