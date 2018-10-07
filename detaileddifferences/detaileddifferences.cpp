#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str1, str2;
    cin >> str1 >> str2;
    cout << str1 << endl << str2 << endl;
    for (int j = 0; j < str1.size(); j++) {
      cout << (str1[j] == str2[j] ? '.' : '*');
    }
    cout << endl << endl;
  }
  return 0;
}
