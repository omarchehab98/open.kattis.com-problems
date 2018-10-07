#include <iostream>
#include <vector>

using namespace std;

struct user {
	vector<int> links;
	unsigned long squawks;
};

int main() {
	int numberOfUsers, numberOfLinks, startIndex, numberOfMinutes;
	scanf("%d %d %d %d", &numberOfUsers, &numberOfLinks, &startIndex, &numberOfMinutes);

	user users[numberOfUsers];

	for (int i = 0; i < numberOfUsers; i++) {
		users[i].squawks = 0;
	}

	users[startIndex].squawks = 1;

	for (int i = 0; i < numberOfLinks; i++) {
		int user1, user2;
		scanf("%d %d", &user1, &user2);

		users[user1].links.push_back(user2);
		users[user2].links.push_back(user1);
	}

	unsigned long numberOfSquawks;
	for (int t = 0; t < numberOfMinutes; t++) {
		numberOfSquawks = 0;

		unsigned long squacks[numberOfUsers];
		for (int i = 0; i < numberOfUsers; i++) {
			squacks[i] = 0;
		}

		for (int i = 0; i < numberOfUsers; i++) {
			for (int j = 0; j < users[i].links.size(); j++) {
				squacks[users[i].links[j]] += users[i].squawks;
				numberOfSquawks += users[i].squawks;
			}
		}

		for (int i = 0; i < numberOfUsers; i++) {
			users[i].squawks = squacks[i];
		}
	}
	cout << numberOfSquawks;
	return 0;
}