#include <iostream>

using namespace std;

int x[1001];

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    int sum = 0;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (x[j] <= x[i]) {
          sum++;
        }
      }
    }
    cout << sum << endl;
  }
  return 0;
}
