#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int numberOfTests;
	cin >> numberOfTests;

	for (int i = 0; i < numberOfTests; i++) {
		int numberOfCalories;
		cin >> numberOfCalories;
		cout << ceil(numberOfCalories / 400.0) << endl;
	}
}