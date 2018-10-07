#include <iostream>

using namespace std;

struct vector2 {
	int x;
	int y;
};

int main() {
	vector2 size;
	vector2 stretch;
	scanf("%d %d %d %d", &size.y, &size.x, &stretch.y, &stretch.x);
	char scanStretch[size.y * stretch.y][size.x * stretch.x];
	for (int y = 0; y < size.y * stretch.y; y+=stretch.y) {
		for (int x = 0; x < size.x * stretch.x; x+=stretch.x) {
			char scanned;
			cin >> scanned;
			for (int dy = 0; dy < stretch.y; dy++) {
				for (int dx = 0; dx < stretch.x; dx++) {
					scanStretch[y + dy][x + dx] = scanned;
				}
			}
		}
	}
	for (int y = 0; y < size.y * stretch.y; y++) {
		for (int x = 0; x < size.x * stretch.x; x++) {
			cout << scanStretch[y][x];
		}
		cout << endl;
	}
	return 0;
}