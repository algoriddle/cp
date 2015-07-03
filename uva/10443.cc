#include <iostream>

using namespace std;

char m[2][101][101];
int r, c;
char b[4] = { 'S', ' ', 'P', 'R' };

bool match(int mi, char bt, int y, int x) {
  return x >= 0 && y >= 0 && x < c && y < r && m[mi][y][x] == bt;
}

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  bool first = true;
  while (t--) {
    int n;
    cin >> r >> c >> n;
    //cout << r << ' ' << c << ' ' << n << endl;
    if (r == 0 || c == 0) {
      continue;
    }
    for (int i = 0; i < r; i++) {
      string s;
      cin >> s;
      s.copy(m[0][i], c);
      m[0][i][c] = 0;
      m[1][i][c] = 0;
      //cout << m[0][i] << endl;
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
          int mi = k % 2;
          char curr = m[mi][i][j];
          char bt = b[curr - 'P'];
          m[!mi][i][j] = (match(mi, bt, i - 1, j)
                          || match(mi, bt, i + 1, j)
                          || match(mi, bt, i, j - 1)
                          || match(mi, bt, i, j + 1)) ? bt : curr;
        }
      }
    }
    if (!first) {
      cout << endl;
    }
    first = false;
    for (int i = 0; i < r; i++) {
      cout << m[n % 2][i] << endl;
    }
  }
  return 0;
}
