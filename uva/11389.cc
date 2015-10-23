#include <algorithm>
#include <iostream>

using namespace std;

int am[100], pm[100];

int main() {
  ios::sync_with_stdio(false);
  for (int n, d, r; cin >> n >> d >> r && n && d && r; ) {
    for (int i = 0; i < n; ++i) {
      cin >> am[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> pm[i];
    }
    sort(am, am + n);
    sort(pm, pm + n);
    int total = 0;
    for (int i = 0; i < n; i++) {
      int j = n - i - 1;
      total += max(0, am[i] + pm[j] - d) * r;
    }
    cout << total << endl;
  }
  return 0;
}
