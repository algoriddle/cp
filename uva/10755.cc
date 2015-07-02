#include <cstring>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  bool first = true;
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    long long p[a + 1][b + 1][c + 1];
    memset(p, 0, sizeof p);
    for (int i = 1; i <= a; i++) {
      for (int j = 1; j <= b; j++) {
        for (int k = 1; k <= c; k++) {
          cin >> p[i][j][k];
          p[i][j][k] += p[i][j][k - 1] + p[i][j - 1][k]
            - p[i][j - 1][k - 1];
        }
      }
    }
    long long global_max = p[1][1][1];
    for (int j1 = 1; j1 <= b; j1++) {
      for (int k1 = 1; k1 <= c; k1++) {
        for (int j2 = j1; j2 <= b; j2++) {
          for (int k2 = k1; k2 <= c; k2++) {
            long long local_max = p[1][j2][k2] - p[1][j2][k1 - 1]
              - p[1][j1 - 1][k2] + p[1][j1 - 1][k1 - 1];
            global_max = max(global_max, local_max);
            //cout << local_max << endl;
            for (int i = 2; i <= a; i++) {
              long long x = p[i][j2][k2] - p[i][j2][k1 - 1]
                - p[i][j1 - 1][k2] + p[i][j1 - 1][k1 - 1];
              //cout << x << endl;
              local_max = max(x, local_max + x);
              global_max = max(global_max, local_max);
            }
          }
        }
      }
    }
    if (!first) {
      cout << endl;
    }
    first = false;
    cout << global_max << endl;
  }
  return 0;
}
