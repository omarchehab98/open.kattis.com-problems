#include <iostream>
#include <regex>

using namespace std;

int main() {
  string str;
  cin >> str;
  for (int i = 97; i <= 122; i++) {
    string s;
    s.push_back(char(i));
    regex e(s+"+");
    str = regex_replace(str, e, s);
  }
  cout << str;
}
