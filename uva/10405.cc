#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  for (string s1, s2; getline(cin, s1) && getline(cin, s2); ) {
    int n1 = s1.length(), n2 = s2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
    for (int i1 = 0; i1 < n1; ++i1) {
      for (int i2 = 0; i2 < n2; ++i2) {
        dp[i1 + 1][i2 + 1] = 
          s1[i1] == s2[i2] ? 
          dp[i1][i2] + 1 :
          max(dp[i1][i2 + 1], dp[i1 + 1][i2]);
      }
    }
    cout << dp[n1][n2] << endl;    
  }
  return 0;
}
