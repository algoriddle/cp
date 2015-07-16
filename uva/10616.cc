#include <iostream>
#include <cstring>

using namespace std;

int n, d, x[200];

int memo[200][20][10];

int count(int i, int r, int m) {
  if (m == 0) {
    return r == 0;
  }
  if (i > n - m) {
    return 0;
  }
  if (memo[i][r][m - 1] == 0) {
    memo[i][r][m - 1] = count(i + 1, ((r + x[i]) % d + d) % d, m - 1)
      + count(i + 1, r, m) + 1;
  }
  return memo[i][r][m - 1] - 1;
}

int main() {
  ios::sync_with_stdio(false);
  for (int q, s = 1; cin >> n >> q && n && q; s++) {
    for (int i = 0; i < n && cin >> x[i]; i++) ;
    cout << "SET " << s << ':' << endl;
    for (int m, qi = 1; qi <= q && cin >> d >> m; qi++) {
      memset(memo, 0, sizeof memo);
      cout << "QUERY " << qi << ": " << count(0, 0, m) << endl;
    }
  }
  return 0;
}
