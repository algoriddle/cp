#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double p;

double f(double x) {
  return x * x - p;
}

double fd(double x) {
  return 2.0L * x;
}
  
int main() {
  ios::sync_with_stdio(false);
  cout << setiosflags(ios::fixed) << setprecision(4);
  while (cin >> p) {
    double x = p / 2.0L;
    while (fabs(f(x)) > 0.00000001L) {
      x = x - f(x) / fd(x);
    }
    cout << x << endl;
  }
  return 0;
}
