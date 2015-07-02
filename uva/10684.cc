#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  while (1) {
    int n;
    cin >> n;
    if (!n) {
      break;
    }
    long long x;
    cin >> x;
    long long local_max = x;
    long long global_max = x;
    while (--n) {
      cin >> x;
      local_max = max(x, local_max + x);
      global_max = max(global_max, local_max);
    }
    if (global_max > 0) {
      cout << "The maximum winning streak is " << global_max << "." << endl;
    } else {
      cout << "Losing streak." << endl;
    }
  }
}
