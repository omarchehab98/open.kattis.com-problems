#include <iostream>

using namespace std;

struct point {
	int x, y;
};

int main() {
	point p[4];
	cin >> p[0].x >> p[0].y
		>> p[1].x >> p[1].y
		>> p[2].x >> p[2].y;
	int x1 = p[0].x, occurencesOfX1 = 1, x2;
	int y1 = p[0].y, occurencesOfY1 = 1, y2;
	for (int i = 1; i < 3; i++) {
		if (x1 == p[i].x) occurencesOfX1++;
		else x2 = p[i].x;
		if (y1 == p[i].y) occurencesOfY1++;
		else y2 = p[i].y;
	}
	if (occurencesOfX1 == 1) cout << x1;
	else cout << x2;
	cout << " ";
	if (occurencesOfY1 == 1) cout << y1;
	else cout << y2;
}