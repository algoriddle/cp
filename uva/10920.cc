#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int sz, p;
  while (cin >> sz >> p && sz && p) {
    int w, q = 1, x = sz / 2 + 1, y = x, s = 1;
    while (q < p) {
      w = min(p - q, s);
      y += w;
      q += w;
      w = min(p - q, s);
      x -= w;
      q += w;
      s++;
      w = min(p - q, s);
      y -= w;
      q += w;
      w = min(p - q, s);
      x += w;
      q += w;
      s++;
    }
    cout << "Line = " << y << ", column = " << x << '.' << endl;
  }
  return 0;
}
