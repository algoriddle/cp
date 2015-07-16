#include <array>
#include <bitset>
#include <cstring>
#include <iostream>
#include <limits>

using namespace std;

const int max_m = 40;
const int max_S = 301;

int m, S;
array<pair<int, int>, max_m> c;
bitset<max_S * max_S> square;
array<int, max_S> squares;

int memo[max_S][max_S];

int count(int x, int y) {
  int r = numeric_limits<int>::max();
  if (x == 0 && y == 0) {
    return 0;
  }
  if (x < 0 || y < 0) {
    return r;
  }
  if (memo[x][y] == 0) {
    for (int i = 0; i < m; i++) {
      r = min(r, count(x - c[i].first, y - c[i].second));
    }
    if (r != numeric_limits<int>::max()) {
      ++r;
    }
    memo[x][y] = r;
  }
  return memo[x][y];
}

int main() {
  ios::sync_with_stdio(false);
  for (int i = 0; i < max_S; i++) {
    int j = i * i;
    squares[i] = j;
    square[j] = true;
  }
  int n;
  cin >> n;
  while (n--) {
    cin >> m >> S;
    for (int i = 0; i < m; i++) {
      cin >> c[i].first >> c[i].second;
    }
    int SS = S * S;
    int r = numeric_limits<int>::max();
    memset(memo, 0, sizeof memo);
    for (int x = 0; x <= S; x++) {
      int y = SS - x * x;
      if (square[y]) {
        y = lower_bound(squares.begin(), squares.end(), y) - squares.begin();
        //cout << x << ' ' << y << endl;
        r = min(r, count(x, y));
      }
    }
    if (r == numeric_limits<int>::max()) {
      cout << "not possible" << endl;
    } else {
      cout << r << endl;
    }
  }
  return 0;
}
