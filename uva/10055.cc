#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int64_t i, j;
  while (cin >> i >> j) {
    cout << (j > i ? j - i : i - j) << endl;
  }
}
