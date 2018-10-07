#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int numberOfTasks, remainingTime, i, completedTasks;
  bool sufficientTime;

  cin >> numberOfTasks >> remainingTime;

  sufficientTime = true;
  completedTasks = 0;
  for (i = 0; i < numberOfTasks; i++) {
    int time;
    cin >> time;
    if (sufficientTime && remainingTime - time >= 0) {
      remainingTime -= time;
      completedTasks ++;
    } else {
      sufficientTime = false;
    }
  }
  cout << completedTasks;
}
