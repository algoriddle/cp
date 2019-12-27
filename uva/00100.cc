#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> l;

int length(int q) {
  return l[q] = l[q] ? l[q]
    : q == 1 ? 1 : length(q % 2 == 0 ? q / 2 : q * 3 + 1) + 1;
}

int main() {
  ios::sync_with_stdio(false);
  int i, j;
  while (cin >> i >> j) {
    int k = min(i, j), e = max(i, j), m = 0;
    for (; k <= e; ++k) {
      m = max(length(k), m);
    }
    cout << i << ' ' << j << ' ' << m << endl;
  }
}
