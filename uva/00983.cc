#include <iostream>
#include <array>

using namespace std;

array<array<long long, 1001>, 1001> dp {};

int main() {
  ios::sync_with_stdio(false);
  bool first = true;
  for (int N, M; cin >> N >> M; ) {
    if (!first) {
      cout << endl;
    }
    first = false;
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        cin >> dp[i][j];
        dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]; 
      }
    }
    int L = N - M;
    long sum = 0;
    for (int i = 0; i <= L; ++i) {
      for (int j = 0; j <= L; ++j) {
        long m = dp[i + M][j + M] - dp[i][j + M] - dp[i + M][j] + dp[i][j];
        sum += m;
        cout << m << endl;
      }
    }
    cout << sum << endl;
  }
  return 0;
}
