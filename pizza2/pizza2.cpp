#include <bits/stdc++.h>

using namespace std;

int main() {
	long double radius, crust;
	long double PI = acos(-1);
	cin >> radius >> crust;
	cout << setprecision(30) << ((PI * pow(radius - crust, 2)) / (PI * pow(radius, 2)) * 100) << endl;
	return 0;
}