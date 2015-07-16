#include <iostream>

using namespace std;

int t, n, x[12], r[12];

bool found;

void sum(int i, int l, int s) {
  if (s > t) {
    return;
  }
  if (s == t) {
    for (int j = 0; j < l; j++) {
      if (j > 0) {
        cout << '+';
      }
      cout << r[j];
    }
    cout << endl;
    found = true;
    return;
  }
  if (i == n) {
    return;
  }
  r[l] = x[i];
  sum(i + 1, l + 1, s + x[i]);
  while (i + 1 < n && x[i + 1] == x[i]) {
    i++;
  }
  sum(i + 1, l, s);
}

int main() {
  ios::sync_with_stdio(false);
  while (cin >> t >> n && t && n) {
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    found = false;
    cout << "Sums of " << t << ':' << endl;
    sum(0, 0, 0);
    if (!found) {
      cout << "NONE" << endl;
    }
  }
  return 0;
}
