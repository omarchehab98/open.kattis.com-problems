#include <iostream>

using namespace std;

int main() {
	int current;
	cin >> current;
	current--; // [1-8] -> [0-7]
	int numberOfQuestions;
	cin >> numberOfQuestions;
	int elapsed = 0;
	int explosion;
	for (int i = 0; i < numberOfQuestions; i++) {
		int time;
		char result;
		cin >> time >> result;
		elapsed += time;
		if (elapsed < 210) { // <
			if (result == 'T') {
				current = (current + 1) % 8;
			}
		} else {
			explosion = current;
		}
	}
	cout << (explosion + 1);
	return 0;
}