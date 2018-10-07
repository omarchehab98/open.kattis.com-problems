#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  vector<string> moves = {};
  int i, x = 0, y = 0, minX = 0, maxX = 0, minY = 0, maxY = 0, sizeX, sizeY;
  char m[5];
  while(scanf("%5s" , &m[0]) != EOF) {
    string move = m;
    moves.push_back(move);
  }
  for (i = 0; i < moves.size(); i++) {
    if (moves[i] == "up") {
      y--;
    } else if (moves[i] == "right") {
      x++;
    } else if (moves[i] == "down") {
      y++;
    } else if (moves[i] == "left") {
      x--;
    }
    if (x > maxX) {
      maxX = x;
    } else if (x < minX) {
      minX = x;
    }
    if (y > maxY) {
      maxY = y;
    } else if (y < minY) {
      minY = y;
    }
  }
  sizeY = maxY - minY + 1;
  sizeX = maxX - minX + 1;
  char map[sizeY][sizeX];
  for (y = 0; y < sizeY; y++) {
    for (x = 0; x < sizeX; x++) {
      map[y][x] = ' ';
    }
  }
  x = abs(minX);
  y = abs(minY);
  map[y][x] = 'S';
  for (i = 0; i < moves.size(); i++) {
    if (moves[i] == "up") {
      y--;
    } else if (moves[i] == "right") {
      x++;
    } else if (moves[i] == "down") {
      y++;
    } else if (moves[i] == "left") {
      x--;
    }
    if (map[y][x] == ' ') {
      map[y][x] = '*';
    }
  }
  map[y][x] = 'E';
  for (x = 0; x < sizeX + 2; x++) {
    cout << "#";
  }
  cout << endl;
  for (y = 0; y < sizeY; y++) {
    cout << "#";
    for (x = 0; x < sizeX; x++) {
      cout << map[y][x];
    }
    cout << "#";
    cout << endl;
  }
  for (x = 0; x < sizeX + 2; x++) {
    cout << "#";
  }
  cout << endl;
}
