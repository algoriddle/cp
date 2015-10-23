#include <iostream>
#include <vector>

using namespace std;

void dfs(int i,
         const vector<vector<int>>& g,
         vector<bool>& visited,
         vector<int>& result)
{
  visited[i] = true;
  for (const int& j : g[i]) {
    if (!visited[j]) {
      dfs(j, g, visited, result);
    }
  }
  result.emplace_back(i);
}

int main() {
  ios::sync_with_stdio(false);
  for (int n, m; cin >> n >> m && n; ) {
    vector<vector<int>> g(n);
    while (m--) {
      int a, b;
      cin >> a >> b;
      g[a - 1].emplace_back(b - 1);
    }
    vector<bool> visited(n);
    vector<int> result;
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        dfs(i, g, visited, result);
      }
    }
    for (int i = result.size() - 1; i >= 0; --i) {
      cout << result[i] + 1;
      if (i) {
        cout << ' ';
      }
    }
    cout << endl;
  }
  return 0;
}
