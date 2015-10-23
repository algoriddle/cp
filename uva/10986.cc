#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  for (int t = 1; t <= N; t++) {
    int n, m, S, T;
    cin >> n >> m >> S >> T;
    vector<vector<pair<int, int>>> g(n);
    while (m--) {
      int s1, s2, l;
      cin >> s1 >> s2 >> l;
      g[s1].emplace_back(s2, l);
      g[s2].emplace_back(s1, l);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> tl(n, numeric_limits<int>::max());
    tl[S] = 0;
    q.emplace(0, S);
    while (!q.empty() && q.top().second != T) {
      int l = q.top().first;
      int s1 = q.top().second;
      q.pop();
      if (l > tl[s1]) {
        continue;
      }
      for (const auto& sp : g[s1]) {
        int s2 = sp.first;
        int nl = l + sp.second;
        if (tl[s2] > nl) {
          q.emplace(nl, s2);
          tl[s2] = nl;
        }
      }
    }
    cout << "Case #" << t << ": ";
    if (q.empty()) {
      cout << "unreachable" << endl;
    } else {
      cout << tl[T] << endl;
    }
  }
  return 0;
}
