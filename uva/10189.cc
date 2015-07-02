#include <iostream>
#include <vector>

using namespace std;

int n, m;

void inc(vector<string>& t, int i, int j) {
  if (i < 0 || j < 0 || i >= n || j >= m || t[i][j] == '*') {
    return;
  }
  if (t[i][j] == '.') {
    t[i][j] = '1';
  } else {
    t[i][j]++;
  }
}

int main() {
  ios::sync_with_stdio(false);
  int c = 1;
  while (cin >> n >> m && n && m) {
    cin.ignore();
    vector<string> t(n);
    for (int i = 0; i < n; i++) {
      getline(cin, t[i]);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (t[i][j] == '.') {
          t[i][j] = '0';
        } else if (t[i][j] == '*') {
          inc(t, i - 1, j - 1);
          inc(t, i - 1, j    );
          inc(t, i - 1, j + 1);
          inc(t, i    , j - 1);
          inc(t, i    , j + 1);
          inc(t, i + 1, j - 1);
          inc(t, i + 1, j    );
          inc(t, i + 1, j + 1);
        }
      }
    }
    if (c > 1) {
      cout << endl;
    }
    cout << "Field #" << c << ':' << endl;
    for (int i = 0; i < n; i++) {
      cout << t[i] << endl;
    }
    c++;
  }
  return 0;
}
