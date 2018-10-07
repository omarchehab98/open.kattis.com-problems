#include <iostream>

using namespace std;

string getOrder(string previous, string current) {
	int largest = max(previous.size(), current.size());
	for (int i = 0; i < largest; i++) {
		int delta = (i <= current.size() ? current[i] : 64) -  (i <= previous.size() ? previous[i] : 64);
		if (delta > 0) {
			return "INCREASING";
		} else if (delta < 0) {
			return "DECREASING";
		}
	}
	return "NEITHER"; // previous == current
} 

int main () {
	int numberOfStudents = 0;
	cin >> numberOfStudents;

	string previous = "";
	string previousOrder = ""; // "DECREASING", "INCREASING", "NEITHER"
	for (int i = 0; i < numberOfStudents; i++) {
		string current;
		cin >> current;
		if (previousOrder == "NEITHER") {
			continue;
		}
		if (previous != "") {
			string currentOrder = getOrder(previous, current);
			if (previousOrder != "" && previousOrder != currentOrder) {
				previousOrder = "NEITHER";
			} else {
				previousOrder = currentOrder;
			}
		}
		previous = current;
	}
	cout << previousOrder;

	return 0;
}