#include <iostream>
#include <bitset>

using namespace std;

const int n = 8;

int q[n], max_cnt, cnt;

bitset<n> orw;
bitset<n * 2 - 1> odd, odu;

void backtrack(int c) {
  if (c == n) {
    max_cnt = max(max_cnt, cnt);
    return;
  }
  for (int r = 0; r < n; r++) {
    if (!orw[r] && !odd[r - c + n - 1] && !odu[r + c]) {
      orw[r] = odd[r - c + n - 1] = odu[r + c] = true;
      if (q[c] == r) {
        ++cnt;
      }
      backtrack(c + 1);
      if (q[c] == r) {
        --cnt;
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
    max_cnt = 0;
    cnt = 0;
    backtrack(0);
    cout << "Case " << ++sol << ": " << 8 - max_cnt << endl;
  }
  return 0;
}
