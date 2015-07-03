#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  while (1) {
    int h, u, d, f, p, i;
    cin >> h;
    if (h == 0) {
      break;
    }
    cin >> u >> d >> f;
    h *= 100;
    u *= 100;
    d *= 100;
    f = (u * f) / 100;
    p = 0;
    i = 0;
    while (1) {
      i++;
      p += u;
      //cout << p << endl;
      if (p > h) {
        cout << "success on day " << i << endl;
        break;
      }
      p -= d;
      //cout << p << endl;
      if (p < 0) {
        cout << "failure on day " << i << endl;
        break;
      }
      u -= f;
      if (u < 0) {
        u = 0;
      }
    }
  }
  return 0;
}
