#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int s, d;
    cin >> s >> d;
    d += s;
    int x = d / 2;
    int y = s - x;
    if ((d & 1) != 0 || y < 0) {
      cout << "impossible" << endl;
    } else {
      cout << x << ' ' << y << endl;
    }
  }
}
