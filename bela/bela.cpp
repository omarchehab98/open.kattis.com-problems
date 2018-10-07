#include <iostream>

using namespace std;

int main() {
	int numberOfHands;
	cin >> numberOfHands;
	
	char trump;
	cin >> trump;
	
	int total = 0;

	for (int i = 0; i < numberOfHands * 4; i++) {
		string card;
		cin >> card;
		switch (card[0]) {
			case 'A':
				total += (trump == card[1]) ? 11 : 11;
				break;
			case 'K':
				total += (trump == card[1]) ? 4 : 4;
				break;
			case 'Q':
				total += (trump == card[1]) ? 3 : 3;
				break;
			case 'J':
				total += (trump == card[1]) ? 20 : 2;
				break;
			case 'T':
				total += (trump == card[1]) ? 10 : 10;
				break;
			case '9':
				total += (trump == card[1]) ? 14 : 0;
				break;
		}
	}
	cout << total;
}