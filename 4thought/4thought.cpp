#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int eval(int o, int a, int b) {
  switch (o) {
    case 0:
      return a * b;
    case 1:
      return a / b;
    case 2:
      return a + b;
    case 3:
      return a - b;
  }
  return 0;
}

void solve(int n) {
  vector<char> operators = {'*','/','+','-'};
  for (int c = 0; c < 4; c++) {
    for (int b = 0; b < 4; b++) {
      for (int a = 0; a < 4; a++) {
        vector<int> ops = {a,b,c};
        vector<int> nums = {4,4,4,4};
        int ans = 0;
        for (int i = 0; i < ops.size(); i++) {
          if (ops[i] >= 2) {
            continue;
          }
          nums[i] = eval(ops[i],nums[i],nums[i + 1]);
          ops.erase(ops.begin() + i);
          nums.erase(nums.begin() + i + 1);
          i--;
        }
        for (int i = 0; i < ops.size(); i++) {
          nums[i] = eval(ops[i],nums[i],nums[i + 1]);
          ops.erase(ops.begin() + i);
          nums.erase(nums.begin() + i + 1);
          i--;
        }
        if (nums[0] == n) {
          cout << "4 " << operators[a] << " 4 " << operators[b] << " 4 " << operators[c] <<  " 4 = " << nums[0] << endl;
          return;
        }
      }
    }
  }
  cout << "no solution" << endl;
  return;
}

int main() {
  int numberOfTests, m;
  cin >> numberOfTests;

  for (m = 0; m < numberOfTests; m++) {
    int n;
    cin >> n;
    solve(n);
  }
}
