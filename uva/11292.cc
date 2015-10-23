#include <algorithm>
#include <iostream>

using namespace std;

int d[20000], k[20000];

int main() {
  ios::sync_with_stdio(false);
  for (int n, m; cin >> n >> m && n && m; ) {
    for (int i = 0; i < n; i++) {
      cin >> d[i];
    }
    for (int i = 0; i < m; i++) {
      cin >> k[i];
    }
    sort(d, d + n);
    sort(k, k + m);
    int t = 0;
    int i = 0;
    for (int j = 0; i < n && j < m; ) {
      if (d[i] <= k[j]) {
        t += k[j];
        ++i;
        ++j;
      } else {
        ++j;
      }
    }
    if (i == n) {
      cout << t << endl;
    } else {
      cout << "Loowater is doomed!" << endl;
    }
  }
  return 0;
}
