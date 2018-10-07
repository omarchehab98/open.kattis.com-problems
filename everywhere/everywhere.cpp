#include <iostream>
#include <algorithm>

using namespace std;

int main () {
  int t;

  cin >> t;

  while (t-- > 0) {
    int n, numberOfUniqueCities = 0;
    string cities[100];

    cin >> n;
    
    while (n-- > 0) {
      string* start = begin(cities);
      string* end = begin(cities) + numberOfUniqueCities;
      string city;
      cin >> city;
      string* result = find(start, end, city);
      if (result == end) {
          cities[numberOfUniqueCities++] = city;
      }
    }
    
    cout << numberOfUniqueCities << endl;
  }
}
