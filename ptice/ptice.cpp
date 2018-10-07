#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
  int numberOfQuestions, i, j, largestScore;
  vector<string> participantNames = {
    "Adrian",
    "Bruno",
    "Goran"
  };
  vector<vector<char>> participantSequences = {
    {'A','B','C'},
    {'B','A','B','C'},
    {'C','C','A','A','B','B'}
  };
  vector<int> participantScores = {
    0,
    0,
    0
  };
  largestScore = 0;

  cin >> numberOfQuestions;

  for (i = 0; i < numberOfQuestions; i++) {
    char answer;
    cin >> answer;
    for (j = 0; j < participantScores.size(); j++) {
      if (answer == participantSequences[j][i % participantSequences[j].size()]) {
        participantScores[j] = participantScores[j] + 1;
        if (participantScores[j] > largestScore) {
          largestScore = participantScores[j];
        }
      }
    }
  }

  cout << largestScore;
  for (i = 0; i < participantScores.size(); i++) {
    if (participantScores[i] == largestScore) {
      cout << endl << participantNames[i];
    }
  }
}
