#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cout << setiosflags(ios::fixed) << setprecision(3);
  while (1) {
    int h, m;
    cin >> h;
    cin.ignore();
    cin >> m;
    if (!h && !m) {
      break;
    }
    double d = fabs((h * 30.0 + m / 2.0) - (m * 6.0));
    if (d > 180.0) {
      d = 360.0 - d;
    }
    cout << d << endl;
  }
  return 0;
}
