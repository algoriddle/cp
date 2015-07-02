#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int l = 1; l <= t; l++) {
    int n, m, k;
    cin >> n >> m >> k;
    int p[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> p[i][j];
        if (i > 0) {
          p[i][j] += p[i - 1][j];
        }
      }
    }
    int max_area = 0;
    int max_price = 0;
    for (int i1 = 0; i1 < n; i1++) {
      for (int i2 = i1; i2 < n; i2++) {
        int j1 = 0;
        int j2 = -1;
        int price = 0;
        while (j1 < m) {
          if (price <= k) {
            int area = (j2 - j1 + 1) * (i2 - i1 + 1);
            if (max_area < area) {
              max_area = area;
              max_price = price;
            } else if (max_area == area && max_price > price) {
              max_price = price;
            }
            j2++;
            if (j2 == m) {
              break;
            }
            price += p[i2][j2] - (i1 > 0 ? p[i1 - 1][j2] : 0);
          } else {
            price -= p[i2][j1] - (i1 > 0 ? p[i1 - 1][j1] : 0);
            j1++;
          }
        }
      }
    }
    cout << "Case #" << l << ": " << max_area << ' ' << max_price << endl;
  }
}
