#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  for (int n; cin >> n && n; ) {
    vector<pair<int, int>> bs(n);
    for (int i = 0; i < n; ++i) {
      cin >> bs[i].first >> bs[i].second;
    }
    sort(bs.begin(), bs.end());
    vector<int> dp;
    for (const auto &b : bs) {
      auto it = upper_bound(dp.begin(), dp.end(), b.second);
      if (it == dp.end()) {
        dp.push_back(b.second);
      } else {
        *it = b.second;
      }
    }
    cout << dp.size() << endl;
  }
  cout << '*' << endl;
  return 0;
}
