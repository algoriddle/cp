#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cout << setfill('0');
  while (1) {
    vector<int> c;
    while (1) {
      int t;
      cin >> t;
      if (t == 0) {
        break;
      }
      c.push_back(t);
    }
    if (c.size() == 0) {
      break;
    }
    int i = *min_element(c.begin(), c.end());
    i *= 2;
    int count = 0;
    while (i <= 18000) {
      for (int t : c) {
        if (i % (t * 2) < (t - 5)) {
          count++;
          if (count == c.size()) {
            break;
          }
        } else {
          i = (i / (t * 2) + 1) * (t * 2);
          count = 1;
        }
      }
      if (count == c.size()) {
        break;
      }
    }
    if (i > 18000) {
      cout << "Signals fail to synchronise in 5 hours" << endl;
    } else {
      cout << setw(2) << i / (60 * 60) << ':';
      cout << setw(2) << i % 3600 / 60 << ':';
      cout << setw(2) << i % 60 << endl;
    }
  }
  return 0;
}
