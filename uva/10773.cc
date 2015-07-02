#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cout << setiosflags(ios::fixed) << setprecision(3);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    double d, v, u;
    cin >> d >> v >> u;
    cout << "Case " << i << ": ";
    if (v == 0 || u == 0 || v >= u) {
      cout << "can't determine" << endl;
    } else {
      cout << d / sqrt(u * u - v * v) - d / u << endl;
    }
  }
  return 0;
}
