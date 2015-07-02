#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int minimum = 100;
    int maximum = -1;
    while (n--) {
      int x;
      cin >> x;
      minimum = min(minimum, x);
      maximum = max(maximum, x);
    }
    cout << (maximum - minimum) * 2 << endl;
  }
  return 0;
}
