#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

double dr[100], f[10], r[10];

int main() {
  ios::sync_with_stdio(false);
  cout << setiosflags(ios::fixed) << setprecision(2);
  int fl, rl;
  while (cin >> fl >> rl) {
    for (int i = 0; i < fl; i++) {
      cin >> f[i];
    }
    for (int i = 0; i < rl; i++) {
      cin >> r[i];
    }
    for (int i = 0; i < fl; i++) {
      for (int j = 0; j < rl; j++) {
        dr[i * rl + j] = r[j] / f[i];
      }
    }
    int l = fl * rl;
    sort(dr, dr + l);
    double m = 0;
    for (int i = 1; i < l; i++) {
      m = max(m, dr[i] / dr[i - 1]);
    }
    cout << m << endl;
  }
  return 0;
}
