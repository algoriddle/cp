#include <iostream>
#include <utility>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b) {
      swap(a, b);
    }
    cout << "Case " << i << ": ";
    if (c < a) {
      cout << a;
    } else if (c > b) {
      cout << b;
    } else {
      cout << c;
    }
    cout << endl;
  }
  return 0;
}
