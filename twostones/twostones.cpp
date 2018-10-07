#include <iostream>

using namespace std;

int main() {
	long numberOfStones;
	cin >> numberOfStones;
	cout << ((numberOfStones % 2 == 0) ? "Bob" : "Alice" );
	return 0;
}