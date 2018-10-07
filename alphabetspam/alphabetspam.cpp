#include <bits/stdc++.h>

using namespace std;

int main() {
	string input;
	cin >> input;
	cout << setprecision(10) << (double(input.size() - regex_replace(input, regex("_"), "").size()) / input.size()) << endl;
	cout << setprecision(10) << (double(input.size() - regex_replace(input, regex("[a-z]"), "").size()) / input.size()) << endl;
	cout << setprecision(10) << (double(input.size() - regex_replace(input, regex("[A-Z]"), "").size()) / input.size()) << endl;
	cout << setprecision(10) << (double(input.size() - regex_replace(input, regex("[^_A-Za-z]"), "").size()) / input.size()) << endl;
	return 0;
}