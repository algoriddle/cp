#include <iostream>
#include <cstring>

using namespace std;

int n, m, ms, p[100], f[100];

int memo[100][10001];

int total_favour(int i, int s) {
  if (s > ms) {
    return -1;
  }
  if (i == n) {
    if (m < s && s <= 2000) {
      return -1;
    } else {
      return 0;
    }
  }
  if (memo[i][s] == 0) {
    int r = total_favour(i + 1, s + p[i]);
    if (r >= 0) {
      r += f[i];
    }
    memo[i][s] = max(r, total_favour(i + 1, s)) + 2;
  }
  return memo[i][s] - 2;
}

int main() {
  ios::sync_with_stdio(false);
  while (cin >> m >> n) {
    for (int i = 0; i < n; i++) {
      cin >> p[i] >> f[i];
    }
    memset(memo, 0, sizeof memo);
    ms = m > 1800 ? m + 200 : m;
    cout << total_favour(0, 0) << endl;
  }
  return 0;
}
