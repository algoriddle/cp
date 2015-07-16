#include <iostream>

using namespace std;

int n, r[100001];

bool sim(int k) {
  for (int i = 1; i <= n; i++) {
    int d = r[i] - r[i - 1];
    if (d > k) {
      return false;
    } else if (d == k) {
      k--;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  r[0] = 0;
  for (int c = 1; c <= t; c++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> r[i];
    }
    int start = 0, end = 10000000;
    while (start < end) {
      int mid = start + (end - start) / 2;
      if (sim(mid)) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }
    cout << "Case " << c << ": " << start << endl;
  }
  return 0;
}
