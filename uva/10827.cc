#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int m[n * 2 - 1][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> m[i][j];
        if (i > 0) {
          m[i][j] += m[i - 1][j];
        }
      }
    }
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n; j++) {
        m[i + n][j] = m[i][j] + m[n - 1][j];
      }
    }
    int global_max = m[0][0];
    for (int i1 = 0; i1 < n; i1++) {
      for (int i2 = i1; i2 < i1 + n; i2++) {
        int local_max = m[i2][0] - (i1 > 0 ? m[i1 - 1][0] : 0);
        int local_min = local_max;
        int row_min = local_max;
        int row_total = local_max;
        global_max = max(global_max, local_max);
        for (int j = 1; j < n; j++) {
          int x = m[i2][j] - (i1 > 0 ? m[i1 - 1][j] : 0);
          row_total += x;
          local_max = max(x, local_max + x);
          global_max = max(global_max, local_max);
          local_min = min(x, local_min + x);
          row_min = min(row_min, local_min);
        }
        global_max = max(global_max, row_total - row_min);
      }
    }
    cout << global_max << endl;
  }
  return 0;
}
