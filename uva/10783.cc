#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int s[102];
  s[0] = 0;
  for (int i = 0; i <= 100; ++i) {
    s[i + 1] = s[i] + (i % 2 ? i : 0);
  }
  int n;
  cin >> n;
  for (int k = 1; k <= n; ++k) {
    int i, j;
    cin >> i >> j;
    cout << "Case " << k << ": " << s[j + 1] - s[i] << endl;
  }
}
