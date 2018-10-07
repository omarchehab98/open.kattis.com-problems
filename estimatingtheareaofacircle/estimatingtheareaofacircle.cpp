#include <bits/stdc++.h>

using namespace std;

int main() {
	long double r, m, c;
	long double PI = acos(-1);
	while (scanf("%Lf %Lf %Lf", &r, &m, &c) && r > 0 && m > 0 && c > 0) {
		cout << setprecision(30) << (PI * pow(r, 2)) << " " << (c / m * pow(2 * r, 2)) << endl;
	}
	return 0;
}