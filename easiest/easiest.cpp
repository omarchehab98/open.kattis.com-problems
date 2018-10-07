#include <bits/stdc++.h>

using namespace std;

int sum(int n) {
	int sum = 0;
	string sn = to_string(n);
	for (int i = 0; i < sn.size(); i++) sum += stoi(string() + sn[i]);
	return sum;
}

int main() {
	int n;
	while (scanf("%d", &n) && n > 0) {
		int sn = sum(n);
		for (int i = 11;; i++) {
			if (sn == sum(n * i)) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}