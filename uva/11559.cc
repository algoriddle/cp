#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n;
  while (cin >> n) {
    int b, h, w, m;
    cin >> b >> h >> w;
    m = b + 1;
    while (h--) {
      int p;
      cin >> p;
      for (int i = 0; i < w; i++) {
        int a;
        cin >> a;
        if (a >= n) {
          m = min(m, p * n);
        }
      }
    }
    if (m <= b) {
      cout << m << endl;
    } else {
      cout << "stay home" << endl;
    }
  }
  return 0;
}
