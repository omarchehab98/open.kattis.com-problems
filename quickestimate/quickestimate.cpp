#include <iostream>

using namespace std;

int main() {
	int numberOfCases;
	cin >> numberOfCases;
	for (int i = 0; i < numberOfCases; i++) {
		string number;
		cin >> number;
		cout << number.size() << endl;
	}
	return 0;
}