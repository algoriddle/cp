#include <iostream>
#include <cstring>

using namespace std;

int c[2000001];

int main() {
  ios::sync_with_stdio(false);
  int n;
  while (cin >> n && n) {
    memset(c, 0, sizeof(c));
    int j = 2000001, e = 0;
    while (n--) {
      int i;
      cin >> i;
      c[i]++;
      j = min(i, j);
      e = max(i, e);
    }
    bool nf = false;
    for (; j <= e; ++j) {
      while (c[j]--) {
        if (nf) {
          cout << ' ';
        }
        cout << j;
        nf = true;
      }
    }
    cout << endl;
  }
}
