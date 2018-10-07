#include <iostream>

using namespace std;

int main() {
	string moves;
	cin >> moves;
	int current = 1;
	for (int i = 0; i < moves.size(); i++) {
		switch (moves[i]) {
			case 'A':
				if (current == 1) current = 2;
				else if (current == 2) current = 1;
				break;
			case 'B':
				if (current == 2) current = 3;
				else if (current == 3) current = 2;
				break;
			case 'C':
				if (current == 1) current = 3;
				else if (current == 3) current = 1;
				break;
		}
	}
	cout << current;
}