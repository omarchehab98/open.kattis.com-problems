#include <iostream>

using namespace std;

int main() {
  int targetPieces[6] = {
    1, // king
    1, // queen
    2, // rooks
    2, // bishops
    2, // knight
    8 // pawns
  }, i;

  for (i = 0; i < 6; i++) {
    int numberOfPieces, a;
    cin >> numberOfPieces;
    a = targetPieces[i] - numberOfPieces;
    cout << a;
    if (i < 5) {
      cout << " ";
    }
  }
}
