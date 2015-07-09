#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, n;

bool match(const vector<string>& M, const vector<string>& m, int i, int j, int d) {
  for (int k = 0; k < n; k++) {
    for (int l = 0; l < n; l++) {
      switch (d) {
      case 0:
        if (M[i + k][j + l] != m[k][l]) {
          return false;
        }
        break;
      case 1:
        if (M[i + k][j + l] != m[n - l - 1][k]) {
          return false;
        }
        break;
      case 2:
        if (M[i + k][j + l] != m[n - k - 1][n - l - 1]) {
          return false;
        }
        break;
      case 3:
        if (M[i + k][j + l] != m[l][n - k - 1]) {
          return false;
        }
        break;
      }
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  while (cin >> N >> n && N && n) {
    vector<string> M(N), m(n);
    for (int i = 0; i < N; i++) {
      cin >> M[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> m[i];
    }
    int l = N - n + 1;
    int r[4];
    memset(r, 0, sizeof r);
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < l; j++) {
        for (int k = 0; k < 4; k++) {
          if (match(M, m, i, j, k)) {
            r[k]++;
          }
        }
      }
    }
    cout << r[0] << ' ' << r[1] << ' ' << r[2] << ' ' << r[3] << endl;
  }
  return 0;
}
