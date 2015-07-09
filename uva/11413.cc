#include <iostream>

using namespace std;

int n, m, c[1001];

bool sim(int cap) {
  int vl = 0, vc = 1;
  for (int i = 0; i < n; i++) {
    if (c[i] > cap) {
      return false;
    }
    vl += c[i];
    if (vl > cap) {
      vl = c[i];
      vc++;
      if (vc > m) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) {
      cin >> c[i];
    }
    int start = 0, end = 1000000001;
    while (start < end) {
      int mid = start + (end - start) / 2;
      if (sim(mid)) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }
    cout << start << endl;
  }
  return 0;
}
