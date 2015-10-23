#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int c = 1; c <= t; c++) {
    int n;
    cin >> n;
    int m = n / 2;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (i == m) {
        cout << "Case " << c << ": " << x << endl;
      }
    }
  }
  return 0;
}
