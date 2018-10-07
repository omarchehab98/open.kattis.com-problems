#include <iostream>

using namespace std;

int main() {
	char board[7][7];
	// Default;
	for (int y = 0; y < 7; y++) {
		for (int x = 0; x < 7; x++) {
			board[y][x] = ' ';
		}
	}
	// Top segment
	for (int y = 0; y < 2; y++) {
		for (int x = 2; x < 5; x++) {
			cin >> board[y][x];
		}
	}
	// Mid segment
	for (int y = 2; y < 5; y++) {
		for (int x = 0; x < 7; x++) {
			cin >> board[y][x];
		}
	}
	// Bot segment
	for (int y = 5; y < 7; y++) {
		for (int x = 2; x < 5; x++) {
			cin >> board[y][x];
		}
	}
	int legalMoves = 0;
	for (int y = 0; y < 7; y++) {
		for (int x = 0; x < 7; x++) {
			if (board[y][x] == 'o') {
				legalMoves += y-1 >= 0 && board[y-1][x] == 'o' && y-2 >= 0 && board[y-2][x] == '.' ? 1 : 0;
				legalMoves += y+1 < 7 && board[y+1][x] == 'o' && y+2 < 7 && board[y+2][x] == '.' ? 1 : 0;
				legalMoves += x-1 >= 0 && board[y][x-1] == 'o' && x-2 >= 0 && board[y][x-2] == '.' ? 1 : 0;
				legalMoves += x+1 < 7 && board[y][x+1] == 'o' && x+2 < 7 && board[y][x+2] == '.' ? 1 : 0;
			}
		}
	}
	cout << legalMoves;
	return 0;
}