#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

class union_find {
public:
  union_find(size_t n) {
    size = n;
    count = size;
    parent.resize(size);
    rank.resize(size);
    for (int i = 0; i < size; ++i) {
      parent[i] = i;
      rank[i] = 0;
    }
  }

  int find(int i) {
    if (i < 0 || i >= size) {
      return i;
    }
    while (parent[i] != i) {
      i = parent[i] = parent[parent[i]];
    }
    return i;
  }

  void connect(int i, int j) { // union
    int ci = find(i);
    int cj = find(j);
    if (ci == cj) {
      return;
    }
    if (i < 0 || i >= size) {
      return;
    }
    if (rank[ci] < rank[cj]) {
      parent[ci] = cj;
    } else if (rank[cj] < rank[ci]) {
      parent[cj] = ci;
    } else {
      parent[cj] = ci;
      ++rank[ci];
    }
    --count;
  }

  bool connected(int i, int j) {
    return find(i) == find(j);
  }

  bool all_connected() {
    return count == 1;
  }
  
private:
  vector<int> parent;
  vector<int> rank;
  int size;
  int count;
};

int dfs(const vector<vector<pair<int, int>>>& graph, int current, int parent,
        int target, vector<vector<int>>& memo) {
  if (current == target) {
    return 0;
  }
  int m = numeric_limits<int>::max();
  for (const auto& edge : graph[current]) {
    if (edge.first == parent) {
      continue;
    }
    m = min(m, max(edge.second, dfs(graph, edge.first, current, target, memo)));
  }
  if (m < numeric_limits<int>::max()) {
    memo[current][target] = m + 1;
    memo[target][current] = m + 1;
  }
  return m;
}

int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  for (int C, S, Q; cin >> C >> S >> Q && (C || S || Q); ) {
    vector<tuple<int, int, int>> edges(S);
    for (int i = 0; i < S; i++) {
      int c1, c2, d;
      cin >> c1 >> c2 >> d;
      edges[i] = make_tuple(d, c1 - 1, c2 - 1);
    }
    vector<vector<pair<int, int>>> graph(C);
    union_find uf(C);
    if (Q) {
      sort(edges.begin(), edges.end());
      for (const auto& edge : edges) {
        if (uf.all_connected()) {
          break;
        }
        int c1 = get<1>(edge);
        int c2 = get<2>(edge);
        if (uf.connected(c1, c2)) {
          continue;
        }
        uf.connect(c1, c2);
        int d = get<0>(edge);
        graph[c1].emplace_back(c2, d);
        graph[c2].emplace_back(c1, d);
      }
    }
    if (t > 1) {
      cout << endl;
    }
    cout << "Case #" << t << endl;
    vector<vector<int>> memo(C, vector<int>(C));
    while (Q--) {
      int c1, c2;
      cin >> c1 >> c2;
      --c1; --c2;
      if (uf.connected(c1, c2)) {
        if (memo[c1][c2]) {
          cout << memo[c1][c2] - 1 << endl;
        } else {
          cout << dfs(graph, c1, -1, c2, memo) << endl;
        }
      } else {
        cout << "no path" << endl;
      }
    }
    ++t;
  }
  return 0;
}
