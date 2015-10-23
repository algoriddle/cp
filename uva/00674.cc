#include <iostream>
#include <array>

using namespace std;

const array<int, 5> coins {50, 25, 10, 5, 1};
const int max_money = 7489;
array<int, max_money> dp {};

int main() {
  ios::sync_with_stdio(false);
  dp[0] = 1;
  for (int coin : coins) {
    for (int i = coin; i <= max_money; ++i) {
      dp[i] += dp[i - coin];
    }
  }
  for (int money; cin >> money; ) {
    cout << dp[money] << endl;
  }
  return 0;
}
