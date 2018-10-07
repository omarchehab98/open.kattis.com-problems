#include <bits/stdc++.h>

using namespace std;

int main() {
	int steps[4];
	scanf("%d %d %d %d", &steps[0], &steps[1], &steps[2], &steps[3]);
	sort(begin(steps), end(steps), [](int a,int b){return a > b; });
	cout << (steps[1] * steps[3]);
	return 0;
}