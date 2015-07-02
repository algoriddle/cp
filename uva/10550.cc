#include <array>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  while (1) {
    array<int, 4> c;
    for_each(c.begin(), c.end(), [](int& x){cin >> x; x *= 9;});
    if (all_of(c.begin(), c.end(), [](int x){ return x == 0; })) {
      break;
    }
    cout << ((c[0] - c[1] + 360) % 360
             + (c[2] - c[1] + 360) % 360
             + (c[2] -c[3] + 360) % 360
             + 1080) << endl;
  }
  return 0;
}
