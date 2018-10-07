#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const int DAYINSECONDS = 86400;

int secondsFromDate(string date) {
  return stoi(string()+date[0]+date[1]) * 3600
    + stoi(string()+date[3]+date[4]) * 60
    + stoi(string()+date[6]+date[7]);
}

int main() {
  string start, end;
  int startInSeconds, endInSeconds, time, timeSeconds, timeMinutes, timeHours;
  cin >> start >> end;
  startInSeconds = secondsFromDate(start);
  endInSeconds = secondsFromDate(end);
  if (endInSeconds <= startInSeconds) {
      endInSeconds += DAYINSECONDS;
  }
  time = endInSeconds - startInSeconds;
  timeHours = floor(time / 3600);
  time -= timeHours * 3600;
  timeMinutes = floor(time / 60);
  time -= timeMinutes * 60;
  timeSeconds = floor(time);
  time -= timeSeconds;
  cout << ((timeHours < 10)?"0":string()) << timeHours <<
    ":" << ((timeMinutes < 10)?"0":string()) << timeMinutes <<
    ":" << ((timeSeconds < 10)?"0":string()) << timeSeconds;
}
