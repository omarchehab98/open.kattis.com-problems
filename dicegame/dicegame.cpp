#include <iostream>

using namespace std;

int main() {
	int a1,b1,a2,b2;
	cin >> a1 >> b1 >> a2 >> b2;
	int a3,b3,a4,b4;
	cin >> a3 >> b3 >> a4 >> b4;
	double gunnar = (b1 - a1) / 2.0 + a1 + (b2 - a2) / 2.0 + a2;
	double emma = (b3 - a3) / 2.0 + a3 + (b4 - a4) / 2.0 + a4;
	if (gunnar > emma) cout << "Gunnar";
	else if (emma > gunnar) cout << "Emma";
	else cout << "Tie";
}