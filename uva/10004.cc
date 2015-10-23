#include <iostream>
#include <vector>

using namespace std;

bool dfs(const vector<vector<int>>& m, vector<int>& c, int i, int ci) {
  if (c[i]) {
    return c[i] == ci;
  }
  c[i] = ci;
  int ck = abs(ci - 2) + 1;
  bool bc = true;
  for (int j = 0; j < m[i].size() && bc; j++) {
    bc = dfs(m, c, m[i][j], ck);
  }
  return bc;
}

int main() {
  ios::sync_with_stdio(false);
  int n, l;
  while (cin >> n && n) {
    vector<vector<int>> m(n);
    cin >> l;
    while (l--) {
      int a, b;
      cin >> a >> b;
      m[a].emplace_back(b);
      m[b].emplace_back(a);
    }
    vector<int> c(n);
    /*
    bool bc = true;
    for (int i = 0; i < n && bc; i++) {
      if (!c[i]) {
        bc = dfs(m, c, i, 1);
      }
    }
    */
    bool bc = dfs(m, c, 0, 1);
    cout << (bc ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
  }
  return 0;
}
