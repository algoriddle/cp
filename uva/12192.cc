#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n, m;
  while (cin >> n >> m && n && m) {
    int hl = n + m - 1;
    vector<vector<int>> h(hl);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int x;
        cin >> x;
        h[j - i + n - 1].emplace_back(x);
      }
    }
    /*
    for (int i = 0; i < hl; i++) {
      copy(h[i].begin(), h[i].end(), ostream_iterator<int>(cout, " "));
      cout << endl;
    }
    */
    int q;
    cin >> q;
    while (q--) {
      int l, u;
      cin >> l >> u;
      int r = 0;
      for (int i = 0; i < hl; i++) {
        if (h[i].size() < r) {
          continue;
        }
        auto it = lower_bound(h[i].begin(), h[i].end(), l);
        if (it == h[i].end()) {
          continue;
        }
        int li = it - h[i].begin();
        if (h[i].size() - li < r) {
          continue;
        }
        it = upper_bound(it, h[i].end(), u);
        int ui = it - h[i].begin();
        r = max(r, ui - li);
      }
      cout << r << endl;
    }
    cout << '-' << endl;
  }
  return 0;
}
