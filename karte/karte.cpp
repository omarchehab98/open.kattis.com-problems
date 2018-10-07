#include <iostream>

using namespace std;

int main() {
	string cards;
	cin >> cards;

	int p = 0, k = 0, h = 0, t = 0;

	for (int i = 0; i < cards.size(); i+=3) {
		string card = string() + cards[i] + cards[i + 1] + cards[i + 2];
		for (int j = i + 3; j < cards.size(); j+=3) {
			if (card == string() + cards[j] + cards[j + 1] + cards[j + 2]) {
				printf("GRESKA");
				return 0;
			}
		}
		switch (cards[i]) {
			case 'P':
				p++;
				break;
			case 'K':
				k++;
				break;
			case 'H':
				h++;
				break;
			case 'T':
				t++;
				break;
		}
	}
	printf("%d %d %d %d", 13 - p, 13 - k, 13 - h, 13 - t);
	return 0;
}