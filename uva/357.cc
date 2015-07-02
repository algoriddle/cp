#include <iostream>

using namespace std;

int coins[] = { 1, 5, 10, 25, 50 };

unsigned long long dp[30001][5];

int upto = 0;

unsigned long long count(int n) {
  if (n >= upto) {
    for (int i = 1; i < 5; i++) {
      for (int j = upto; j <= n; j++) {
        dp[j][i] = dp[j][i - 1]
          + (j >= coins[i] ? dp[j - coins[i]][i] : 0);
      }
    }
    upto = n - 1;
  }
  /*
  for (int i = 0; i <= n; i++) {
    cout << i << ": ";
    for (int j = 0; j < 5; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  */
  return dp[n][4];
}

int main() {
  ios::sync_with_stdio(false);
  for (int i = 0; i < 30001; i++) {
    dp[i][0] = 1;
  }
  int n;
  while (cin >> n) {
    unsigned long long m = count(n);
    if (m > 1) {
      cout << "There are " << m << " ways to produce ";
    } else {
      cout << "There is only 1 way to produce ";
    }
    cout << n << " cents change." << endl;
  }
  return 0;
}
