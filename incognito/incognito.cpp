#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  int numberOfTests, n;
  cin >> numberOfTests;

  for (n = 0; n < numberOfTests; n++) {
    
    map<string,vector<string>> categories;
    int numberOfItems;
    cin >> numberOfItems;

    for (int i = 0; i < numberOfItems; i++) {

      string item, category;
      cin >> item >> category;
      
      categories[category].push_back(item);
    }

    vector<int> c;

    for (map<string,vector<string>>::iterator it = categories.begin(); it != categories.end() ; it++) {
      c.push_back(it->second.size());
    }

    // c = 1: x
    // c = 2: x(y+1)                + y
    // c = 3: x(y+1)(z+1)           + y(z+1)           + z
    // c = 4: x(y+1)(z+1)(w+1)      + y(z+1)(w+1)      + z(w+1)      + w
    // c = 5: x(y+1)(z+1)(w+1)(v+1) + y(z+1)(w+1)(v+1) + z(w+1)(v+1) + w(v+1) + v
    int t = 0;
    for (int i = 0; i < c.size(); i++) {
      int product = c[i];
      for (int j = i + 1; j < c.size(); j++) {
          product *= c[j] + 1;
      }
      t += product;
    }
    cout << t << endl;
  }
}
