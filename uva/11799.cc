#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n;
    cin >> n;
    int m;
    cin >> m;
    while (--n) {
      int c;
      cin >> c;
      m = max(m, c);
    }
    cout << "Case " << i << ": " << m << endl;
  }
  return 0;
}
