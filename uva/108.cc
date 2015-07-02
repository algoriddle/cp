#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }
  int m[n][n];
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      cin >> m[r][c];
      if (r > 0) {
        m[r][c] += m[r - 1][c];
      }
    }
  }
  int global_max = m[0][0];
  for (int r1 = 0; r1 < n; r1++) {
    for (int r2 = r1; r2 < n; r2++) {
      int local_max = m[r2][0] - (r1 > 0 ? m[r1 - 1][0] : 0);
      global_max = max(global_max, local_max);
      for (int c = 1; c < n; c++) {
        int x = m[r2][c] - (r1 > 0 ? m[r1 - 1][c] : 0);
        local_max = max(x, local_max + x);
        global_max = max(global_max, local_max);
      }
    }
  }
  cout << global_max << endl;
  return 0;
}
