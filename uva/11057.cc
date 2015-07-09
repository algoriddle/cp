#include <iostream>
#include <limits>
#include <map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n;
  while (cin >> n) {
    map<int, bool> map;
    while (n--) {
      int x;
      cin >> x;
      auto it = map.find(x);
      if (it != map.end()) {
        it->second = true;
      } else {
        map.emplace(x, false);
      }
    }
    int m;
    cin >> m;
    int r, mh = m >> 1, d = numeric_limits<int>::max();
    for (const auto& kv : map) {
      int x = kv.first;
      if (x <= mh && map.find(m - x) != map.end()) {
        if (x == m - x && !kv.second) {
          continue;
        }
        int dd = m - (x << 1);
        if (dd < d) {
          r = x;
          d = dd;
        }
      }
    }
    cout << "Peter should buy books whose prices are "
         << r << " and " << m - r << '.' << endl << endl;
  }
  return 0;
}
