#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n;
  while (cin >> n) {
    bool jolly = true;
    int x[n];
    bool t[n];
    memset(t, 0, sizeof t);
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    for (int i = 1; i < n; i++) {
      int j = abs(x[i] - x[i - 1]);
      if (j > n - 1 || j == 0 || t[j]) {
        jolly = false;
        break;
      }
      t[j] = true;
    }
    if (jolly) {
      cout << "Jolly" << endl;
    } else {
      cout << "Not jolly" << endl;
    }
  }
  return 0;
}
