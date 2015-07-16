#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

const int n = 8;

int col, t[n], sol;

bitset<n> orw;
bitset<n * 2 - 1> odd, odu;

void backtrack(int c) {
  if (c == n) {
    cout << setw(2) << ++sol << "     ";
    for (int i = 0; i < n; i++) {
      cout << setw(2) << t[i] + 1;
    }
    cout << endl;
    return;
  }
  if (col == c) {
    backtrack(c + 1);
  } else {
    for (int r = 0; r < n; r++) {
      if (!orw[r] && !odd[r - c + n - 1] && !odu[r + c]) {
        orw[r] = odd[r - c + n - 1] = odu[r + c] = true;
        t[c] = r;
        backtrack(c + 1);
        orw[r] = odd[r - c + n - 1] = odu[r + c] = false;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cout.fill(' ');
  int d;
  cin >> d;
  for (int q = 0; q < d; q++) {
    if (q > 0) {
      cout << endl;
    }
    cout << "SOLN       COLUMN" << endl;
    cout << " #      1 2 3 4 5 6 7 8" << endl;
    cout << endl;
    int row;
    cin >> row >> col;
    t[--col] = --row;
    orw.reset();
    odd.reset();
    odu.reset();
    orw[row] = odd[row - col + n - 1] = odu[row + col] = true;
    sol = 0;
    backtrack(0);
  }
  return 0;
}
