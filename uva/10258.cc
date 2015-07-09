#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>
#include <tuple>
#include <vector>

using namespace std;

int solved[101][10];
int problems[101];
int times[101];
bool submissions[101];

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  cin.ignore(2);
  bool first = true;
  while (t--) {
    memset(solved, 0, sizeof solved);
    memset(problems, 0, sizeof problems);
    memset(times, 0, sizeof times);
    memset(submissions, 0, sizeof submissions);
    while (true) {
      string s;
      getline(cin, s);
      if (s.length()) {
        stringstream ss(s);
        int c, p, t;
        char l;
        ss >> c >> p >> t >> l;
        submissions[c] = true;
        if (solved[c][p] >= 0) {
          if (l == 'C') {
            times[c] += t + solved[c][p];
            solved[c][p] = -1;
            problems[c]++;
          } else if (l == 'I') {
            solved[c][p] += 20;
          }
        }
      } else {
        vector<tuple<int, int, int>> r;
        for (int i = 0; i < 101; i++) {
          if (submissions[i]) {
            r.emplace_back(-problems[i], times[i], i);
          }
        }
        sort(r.begin(), r.end());
        if (!first) {
          cout << endl;
        }
        first = false;
        for (auto l : r) {
          cout << get<2>(l) << ' ' << -get<0>(l) << ' ' << get<1>(l) << endl;
        }
        break;
      }
    }
  }
  return 0;
}
