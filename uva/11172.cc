#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << (char)((a > b) - (a < b) + 61) << endl;
  }
  return 0;
}
