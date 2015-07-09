#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double p, q, r, s, t, u;

double f(double x) {
  return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double fd(double x) {
  return -p * exp(-x) + q * cos(x) - r * sin(x)
    + s / (cos(x) * cos(x)) + 2.0L * t * x;
}
  
int main() {
  ios::sync_with_stdio(false);
  cout << setiosflags(ios::fixed) << setprecision(4);
  while (cin >> p >> q >> r >> s >> t >> u) {
    if (f(0) * f(1) > 0) {
      cout << "No solution" << endl;
    } else {
      double x = 0.0L;
      if (f(x) != 0.0L) {
        x = 0.5L;
        while (fabs(f(x)) > 0.00000001L) {
          x = x - f(x) / fd(x);
        }
      }
      cout << x << endl;
    }
  }
  return 0;
}
