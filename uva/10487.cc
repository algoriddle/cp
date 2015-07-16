#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;

long long x[1000];

int main() {
  ios::sync_with_stdio(false);
  for (int n, c = 1; cin >> n && n; c++) {
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    sort(x, x + n);
    cout << "Case " << c << ':' << endl;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
      long long q;
      cin >> q;
      long long closest, min_d = numeric_limits<int>::max(), start = 0, end = n - 1;
      while (start < end) {
        long long s = x[start] + x[end];
        long long d = abs(s - q);
        if (d < min_d) {
          min_d = d;
          closest = s;
          if (min_d == 0) {
            break;
          }
        }
        if (s > q) {
          end--;
        } else {
          start++;
        }
      }
      cout << "Closest sum to " << q << " is " << closest << '.' << endl;
    }
  }
  return 0;
}
