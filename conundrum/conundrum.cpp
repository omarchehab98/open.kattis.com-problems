#include <iostream>

using namespace std;

int main() {
	string cipherText;
	cin >> cipherText;
	int numberOfDays = 0;
	for (int i = 0; i < cipherText.size(); i++) {
		if (cipherText[i] != ("PER")[i % 3]) numberOfDays++;
	}
	cout << numberOfDays;
}