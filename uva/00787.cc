#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int x;
  bool first = true;
  int local_min, local_max, global_max;
  while (cin >> x) {
    if (x == -999999) {
      cout << global_max << endl;
      first = true;
      continue;
    }
    if (first) {
      local_min = x;
      local_max = x;
      global_max = x;
      first = false;
    } else {
      local_min *= x;
      local_max *= x;
      int tmp = min(min(local_max, local_min), x);
      local_max = max(max(local_max, local_min), x);
      local_min = tmp;
      global_max = max(global_max, local_max);
    }
  }
  return 0;
}
