#include <iostream>
#include <bitset>

using namespace std;

const int n = 8;

int q[n], max_count, count;

bitset<n> orw;
bitset<n * 2 - 1> odd, odu;

void backtrack(int c) {
  if (c == n) {
    max_count = max(max_count, count);
    return;
  }
  for (int r = 0; r < n; r++) {
    if (!orw[r] && !odd[r - c + n - 1] && !odu[r + c]) {
      orw[r] = odd[r - c + n - 1] = odu[r + c] = true;
      if (q[c] == r) {
        ++count;
      }
      backtrack(c + 1);
      if (q[c] == r) {
        --count;
      }
      orw[r] = odd[r - c + n - 1] = odu[r + c] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  int sol = 0;
  while (cin >> q[0]) {
    --q[0];
    for (int i = 1; i < n; i++) {
      cin >> q[i];
      --q[i];
    }
    orw.reset();
    odd.reset();
    odu.reset();
    max_count = 0;
    count = 0;
    backtrack(0);
    cout << "Case " << ++sol << ": " << 8 - max_count << endl;
  }
  return 0;
}
