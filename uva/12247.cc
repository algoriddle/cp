#include <iostream>
#include <cstring>

using namespace std;

int c[5];
bool cm[53];

int main() {
  ios::sync_with_stdio(false);
  while (true) {
    memset(cm, 0, sizeof cm);
    for (int i = 0; i < 5; i++) {
      cin >> c[i];
      cm[c[i]] = true;
    }
    if (!c[0]) {
      break;
    }
    int l = 0;
    for (int i = 3; i < 5; i++) {
      int w = 100, wi = -1, m = 100, mi = -1;
      for (int j = 0; j < 3; j++) {
        if (c[j] > c[i] && w > c[j]) {
          w = c[j];
          wi = j;
        }
        if (c[j] > 0 && m > c[j]) {
          m = c[j];
          mi = j;
        }
      }
      if (wi >= 0) {
        l++;
        c[wi] = -c[wi];
      } else {
        c[mi] = -c[mi];
      }
    }
    bool fail = true;
    int m = 0;
    if (l == 1) {
      for (int i = 0; i < 3; i++) {
        if (c[i] > 0) {
          m = c[i];
          break;
        }
      }
    }
    if (l < 2) {
      for (int i = m + 1; i <= 52; i++) {
        if (!cm[i]) {
          cout << i << endl;
          fail = false;
          break;
        }
      }
    }
    if (l == 2 || fail) {
      cout << -1 << endl;
    }
  }
  return 0;
}
