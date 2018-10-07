#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	char domain[28] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','_','.'};
	int numberOfRotations;
	while (scanf("%d", &numberOfRotations) && numberOfRotations > 0) {
		string message;
		cin >> message;
		reverse(message.begin(), message.end());
		for (int i = 0; i < message.size(); i++) {
			int index;
			for (index = 0; index < 28; index++) {
				if (domain[index] == message[i]) {
					break;
				}
			}
			message[i] = domain[(index + numberOfRotations) % 28];
		}
		cout << message << endl;
	}
	return 0;
}