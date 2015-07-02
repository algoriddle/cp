#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> pp;

int main() {
  ios::sync_with_stdio(false);
  while (1) {
    int s, b;
    cin >> s >> b;
    if (!s && !b) {
      break;
    }
    /*
    vector<pp> range = {{1, s}};
    while (b--) {
      int l, r;
      cin >> l >> r;
      vector<pp>::iterator q = upper_bound(range.begin(), range.end(), pp(l, 0),
                                           [](const pp& r1, const pp& r2)
                                           {
                                             return r1.first < r2.first;
                                           }) - 1;
      if (q->first < l) {
        q = range.insert(q, pp(q->first, l - 1));
        q++;
      }
      while (q != range.end() && q->second <= r) {
        q = range.erase(q);
      }
      if (q != range.end() && q->first <= r) {
        q->first = r + 1;
      }
      if (q == range.begin()) {
        cout << '*';
      } else {
        cout << (q - 1)->second;
      }
      cout << ' ';
      if (q == range.end()) {
        cout << '*';
      } else {
        cout << q->first;
      }
      cout << endl;
    }
    */
    int left[s + 1];
    int right[s + 1];
    for (int i = 0; i <= s; i++) {
      left[i] = i - 1;
      right[i] = i + 1;
    }
    while (b--) {
      int l, r;
      cin >> l >> r;
      if (left[l] == 0) {
        cout << '*';
      } else {
        cout << left[l];
      }
      cout << ' ';
      if (right[r] > s) {
        cout << '*';
      } else {
        cout << right[r];
      }
      cout << endl;
      left[right[r]] = left[l];
      right[left[l]] = right[r];
    }
    cout << '-' << endl;
  }
  return 0;
}
