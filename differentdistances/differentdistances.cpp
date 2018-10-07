#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double x1, y1, x2, y2, p;
	while (scanf("%lf", &x1) && x1 > 0) {
		scanf("%lf %lf %lf %lf", &y1, &x2, &y2, &p);
		cout << (double(pow(pow(abs(x1 - x2), p) + pow(abs(y1 - y2), p), 1.0 / p))) << endl;
	}
	return 0;
}