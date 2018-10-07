#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string str;
    bool first = true;
    while (getline(cin, str)) {
        if (first) {
            first = false;
        } else {
            cout << endl;
        }
        transform (str.begin(), str.end(), str.begin(), ::tolower);
        if (str.find("problem") != string::npos) cout << "yes";
        else cout << "no";
    }
    return 0;    
}