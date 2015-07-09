#include <array>
#include <iostream>
#include <vector>

using namespace std;

array<vector<int>, 52> st;

int main() {
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int l = s.length();
  for (int i = 0; i < l; i++) {
    char c = s[i];
    int j = c < 'a' ? c - 'A' : c - 'a' + 26;
    st[j].emplace_back(i);
  }
  int q;
  cin >> q;
  while (q--) {
    string ss;
    cin >> ss;
    int l = ss.length();
    int start = -1, current = 0, end = -1;
    for (int i = 0; i < l; i++) {
      char c = ss[i];
      int j = c < 'a' ? c - 'A' : c - 'a' + 26;
      auto it = lower_bound(st[j].begin(), st[j].end(), current);
      if (it == st[j].end()) {
        break;
      }
      current = *it + 1;
      if (i == 0) {
        start = *it;
      }
      if (i == l - 1) {
        end = *it;
      }
    }
    if (end == -1) {
      cout << "Not matched" << endl;
    } else {
      cout << "Matched " << start << ' ' << end << endl;
    }
  }
  return 0;
}
