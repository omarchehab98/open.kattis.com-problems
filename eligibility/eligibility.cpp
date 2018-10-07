#include <iostream>

using namespace std;

int main() {
	int numberOfStudents;
	cin >> numberOfStudents;
	for (int i = 0; i < numberOfStudents; i++) {
		string name, study, born;
		int courses;
		cin >> name >> study >> born >> courses;
		if (stoi(study.substr(0,4)) >= 2010 || stoi(born.substr(0,4)) >= 1991 ) {
			cout << name << " eligible" << endl;
		} else if (courses >= 41) {
			cout << name << " ineligible" << endl;
		} else {
			cout << name << " coach petitions" << endl;
		}
	}
	return 0;
}