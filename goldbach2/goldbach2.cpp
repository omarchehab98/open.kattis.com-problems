#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int number) {
  if (number < 2) {
      return false;
  }
  for (int i = 2; i <= sqrt(number); i++) {
    if (number % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int numberOfTests, numberOfPrimes, i;
  cin >> numberOfTests;
  vector <int> primes;
  for (i = 2; i < 32000; i++) {
    if (isPrime(i)) {
      primes.push_back(i);
    }
  }
  numberOfPrimes = primes.size();
  for (i = 0; i < numberOfTests; i++) {
    vector<int> sum1;
    vector<int> sum2;
    int number;
    cin >> number;
    for (int m = 0; m < numberOfPrimes; m++) {
      if (primes[m] > ceil(number / 2)) {
        break;
      }
      for (int n = 0; n < numberOfPrimes; n++) {
        if (primes[n] > number) {
          break;
        }
        if (primes[m] + primes[n] == number) {
          sum1.push_back(primes[m]);
          sum2.push_back(primes[n]);
        }
      }
    }
    cout << endl << number <<" has "<< sum1.size() <<" representation(s)";
    for (int j = 0; j < sum1.size(); j++) {
        cout << endl << sum1[j] << "+" << sum2[j];
    }
    cout << endl;
  }
}
