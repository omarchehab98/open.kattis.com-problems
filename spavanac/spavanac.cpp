#include <iostream>

using namespace std;

int main() {
	int hours, minutes;
	cin >> hours >> minutes;
	minutes -= 45;
	if (minutes < 0) {
		minutes += 60;
		hours -= 1;
		if (hours < 0) {
			hours += 24;
		}
	}
	cout << hours << " " << minutes;
}