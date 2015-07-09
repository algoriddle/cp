#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int x, y[2], i;
  while (cin >> x && x) {
    y[0] = 0;
    y[1] = 0;
    int i = 0;
    while (x > 0) {
      y[i] |= x & -x;
      x &= x - 1;
      i = !i;
    }
    cout << y[0] << ' ' << y[1] << endl;
  }
  return 0;
}
