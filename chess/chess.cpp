#include <iostream>

using namespace std;

struct point {
	char column;
	int row;
};

string color(point p) {
	if (p.column % 2 == 0) {
		if (p.row % 2 == 0) return "Black";
		else return "White";
	} else {
		if (p.row % 2 == 0) return "White";
		else return "Black";
	}
}

bool isDiagonal(point p1, point p2) {
	return p1.row + p2.column == p2.row + p1.column // (1,1) -> (3,3)
		|| p1.row + p1.column == p2.row + p2.column; // (1,3) -> (3,1)
}

point intersection(point p1, point p2) {
	point p;
	p.row = (p2.row + p2.column + p1.row - p1.column) / 2;
	p.column = (p2.row + p2.column - p1.row + p1.column) / 2;
	if (p.row < 1 || p.row > 8 || p.column < 'A' || p.column > 'H') {
		return intersection(p2, p1);
	}
	return p;
}

int main() {
	int numberOfCases;
	cin >> numberOfCases;
	for (int i = 0; i < numberOfCases; i++) {
		point start, target;
		cin >> start.column >> start.row >> target.column >> target.row;
		
		if (start.column == target.column && start.row == target.row) {
			cout << "0 "
				<< start.column << " " << start.row << endl;
		} else if (color(start) != color(target)) {
			cout << "Impossible" << endl;
		} else if (isDiagonal(start, target)) {
			cout << "1 "
				<< start.column << " " << start.row << " "
				<< target.column << " " << target.row << endl;
		} else {
			point move = intersection(target, start);
			cout << "2 "
				<< start.column << " " << start.row << " "
				<< move.column << " " << move.row << " "
				<< target.column << " " << target.row << endl;
		}
	}
	return 0;
}