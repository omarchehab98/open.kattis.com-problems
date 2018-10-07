#include <iostream>
#include <cmath>

using namespace std;

int main() {
	unsigned long in, out = 0;
	cin >> in;
	while (in) {
		out <<= 1;
		out |= in & 1;
		in >>= 1;
	}
	cout << out << endl;
}