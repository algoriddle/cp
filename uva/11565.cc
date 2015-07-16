#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  while (n--) {
    int a, b, c;
    cin >> a >> b >> c;
    bool found = false;
    for (int x = -100; x <= 100 && !found; x++) {
      for (int y = x + 1; y <= 100 && !found; y++) {
        int z = a - x - y;
        if (z == x || z == y || z < -100 || z > 100) {
          continue;
        }
        if (b == x * y * z && c == x * x + y * y + z * z) {
          cout << x << ' ' << y << ' ' << z << endl;
          found = true;
        }
      }
    }
    if (!found) {
      cout << "No solution." << endl;
    }
  }
}
