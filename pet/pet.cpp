#include <iostream>

using namespace std;

int main() {
    int n, index = -1, maximum = -1;
    for (n = 1; n <= 5; n++) {
        int i, grades = 0;
        for (i = 0; i < 4; i++) {
            int grade;
            cin >> grade;
            grades += grade;
        }
        if (grades > maximum) {
            index = n;
            maximum = grades;
        }
    }
    cout << index << " " << maximum;
}
