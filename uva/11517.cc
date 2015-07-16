#include <iostream>
#include <limits>
#include <vector>

using namespace std;

const int infinity = numeric_limits<int>::max();

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int p, n;
    cin >> p >> n;
    vector<int> dp(p + 1, infinity);
    dp[0] = 0;
    while (n--) {
      int v;
      cin >> v;
      for (int i = p - 1; i >= 0; i--) {
        if (dp[i] < infinity) {
          if (i + v >= dp.size()) {
            dp.resize(i + v + 1, infinity);
          }
          dp[i + v] = min(dp[i + v], dp[i] + 1);
        }
      }
    }
    int rp, rc = 0;
    for (rp = p; rp < dp.size(); rp++) {
      if (dp[rp] < infinity) {
        rc = dp[rp];
        break;
      }
    }
    cout << rp << ' ' << rc << endl;
  }
  return 0;
}
