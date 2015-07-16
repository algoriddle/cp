#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int m;
  while (cin >> m) {
    vector<string> sq(m);
    for (int i = 0; i < m; i++) {
      cin >> sq[i];
    }
    vector<pair<int, int>> ones;
    vector<pair<int, int>> threes;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        if (sq[i][j] == '1') {
          ones.emplace_back(i, j);
        } else if (sq[i][j] == '3') {
          threes.emplace_back(i, j);
        }
      }
    }
    int max_d = 0;
    for (const auto& one : ones) {
      int min_d = m << 1;
      for (const auto& three : threes) {
        int d = abs(one.first - three.first) + abs(one.second - three.second);
        min_d = min(min_d, d);
      }
      max_d = max(max_d, min_d);
    }
    cout << max_d << endl;
  }
  return 0;
}
