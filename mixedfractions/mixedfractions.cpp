#include <iostream>

using namespace std;

int main() {
	int a, b;
	while (scanf("%d %d", &a, &b) && a > 0 && b > 0) {
		cout << (int (a / b)) << " " << (a % b) << " / " << b << endl;
	}
	return 0;
}