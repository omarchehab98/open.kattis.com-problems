#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int currentSet = 0;

	int numberOfEntries;
	while (scanf("%d", &numberOfEntries) && numberOfEntries > 0) {
		currentSet++;
		vector<string> names;
		for (int i = 0; i < numberOfEntries; i++) {
			string name;
			cin >> name;
			names.push_back(name);
		}
		for (int i = 1; i < ceil((numberOfEntries + 1) / 2); i++) {
			string name = names[i];
			names.erase(names.begin() + i);
			names.insert(names.begin() + numberOfEntries - i, name);
		}
		cout << "SET " << currentSet << endl;
		for (int i = 0; i < names.size(); i++) {
			cout << names[i] << endl;
		}
	}
	return 0;
}