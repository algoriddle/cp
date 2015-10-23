#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  for (int n; cin >> n && n; ) {
    bool f = false;
    while (n--) {
      int x;
      cin >> x;
      if (x > 0) {
        if (f) {
          cout << ' ';
        }
        cout << x;
        f = true;
      }
    }
    if (!f) {
      cout << 0;
    }
    cout << endl;
  }
  return 0;
}
