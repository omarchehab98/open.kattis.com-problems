#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

struct question {
	bool solved = false;
	int penalty = 0;
};

int main() {
	std::map<char,question> questions;
	int time;
	while (scanf("%d", &time) && time >= 0) {
		char question;
		string result;
		cin >> question >> result;

		if (result == "wrong") {
			questions[question].penalty += 20;
		} else if (!questions[question].solved) {
			questions[question].solved = true;
			questions[question].penalty += time;
		}
	}
	time = 0;
	int solved = 0;
	for_each(questions.begin(),questions.end(), [&](pair<char,question> q) {
		if (q.second.solved) {
			time += q.second.penalty;
			solved += 1;
		}
	});
	cout << solved << " " << time;
	return 0;
}