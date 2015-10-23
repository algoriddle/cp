#include <iostream>
#include <limits>

using namespace std;

int w[1000][10];
int dp[1000][10];

const int infinity = numeric_limits<int>::max();

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    x /= 100;
    for (int i = 9; i >= 0; i--) {
      for (int j = 0; j < x; j++) {
        cin >> w[j][i];
      }
    }
    for (int i = 0, h = 1; i < x; i++) {
      for (int j = 0; j <= h; j++) {
        int hold = j < h ? (i > 0 ? dp[i - 1][j] : 0)
          - w[i][j] + 30 : infinity;
        int climb = j > 0 ? (i > 0 ? dp[i - 1][j - 1] : 0)
          - w[i][j - 1] + 60 : infinity;
        int sink = j < h - 1 ? (i > 0 ? dp[i - 1][j + 1] : 0)
          - w[i][j + 1] + 20 : infinity;
        dp[i][j] = min(min(hold, climb), sink);
      }
      h = min(h + 1, 9);
    }
    cout << dp[x - 1][0] << endl << endl;
  }
  return 0;
}
