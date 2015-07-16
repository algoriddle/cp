#include <iostream>

using namespace std;

int l[20];

int main() {
  ios::sync_with_stdio(false);
  for (int n, m; cin >> n >> m; ) {
    for (int i = 0; i < m; i++) {
      cin >> l[i];
    }
    int r, max_s = 0;
    int b = 1 << m;
    for (int i = 0; i < b; i++) {
      int s = 0;
      for (int j = 0; j < m; j++) {
        if (i & (1 << j)) {
          s += l[j];
        }
      }
      if (s > n) {
        continue;
      }
      if (s > max_s) {
        r = i;
        max_s = s;
      }
    }
    for (int i = 0; i < m; i++) {
      if (r & (1 << i)) {
        cout << l[i] << ' ';
      }
    }
    cout << "sum:" << max_s << endl;
  }
  return 0;
}
