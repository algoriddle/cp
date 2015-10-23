#include <cstring>
#include <iostream>
#include <limits>
#include <utility>

using namespace std;

const int max_points = 11;

int n;
pair<int, int> p[max_points];
int dp[max_points][1 << max_points];

int point_dist(const pair<int, int>& a, const pair<int, int>& b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

double tsp(int start, int mask) {
  mask &= ~(1 << start);
  int& min_dist = dp[start][mask];
  if (min_dist == 0) {
    if (mask == 0) {
      min_dist = point_dist(p[start], p[0]) + 1;
    } else {
      min_dist = numeric_limits<int>::max();
      for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
          int dist = point_dist(p[start], p[i]) + tsp(i, mask);
          min_dist = min(min_dist, dist);
        }
      }
      ++min_dist;
    }
  }
  return min_dist - 1;
}

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y >> p[0].first >> p[0].second >> n;
    n++;
    for (int i = 1; i < n; i++) {
      cin >> p[i].first >> p[i].second;
    }
    memset(dp, 0, sizeof dp);
    int mask = (1 << n) - 1;
    cout << "The shortest path has length " << tsp(0, mask) << endl;
  }
  return 0;
}
