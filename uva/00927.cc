#include <iostream>
#include <cmath>
#include <vector>

typedef unsigned long long ull;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int C;
  cin >> C;
  while (C--) {
    int t;
    double d, k;
    cin >> t;
    vector<ull> c(t + 1);
    for (int i = 0; i <= t; ++i) {
      cin >> c[i];
    }
    cin >> d >> k;
    ull nb = ull(floor((sqrt(d * (d + 8.0 * (k - 1.0))) - d) / (2.0 * d))) + 1;
    ull r = 0, n = 1;
    for (int i = 0; i <= t; ++i) {
      r += c[i] * n;
      n *= nb;
    }
    cout << r << endl;
  }
  return 0;
}
