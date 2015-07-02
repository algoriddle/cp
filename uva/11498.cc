#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    cout << abs((x * (567 / 9) + 7492) * (235 / 47) - 498) % 100 / 10 << endl;
  }
  return 0;
}
