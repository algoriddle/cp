#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <utility>

using namespace std;

int n;
pair<int, int> p[8];
pair<double, int> dp[9][256];

double point_dist(const pair<int, int>& a, const pair<int, int>& b) {
  return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

double tsp(int start, int mask) {
  if (mask == 0) {
    return 0.0;
  }
  double& min_dist = dp[start][mask].first;
  int& next = dp[start][mask].second;
  if (next == 0) {
    min_dist = numeric_limits<double>::max();
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        double dist = (start == 0 ? 0.0 : point_dist(p[start - 1], p[i]))
          + tsp(i + 1, mask & ~(1 << i));
        if (dist < min_dist) {
          min_dist = dist;
          next = i + 1;
        }
      }
    }
  }
  return min_dist;
}

int main() {
  ios::sync_with_stdio(false);
  cout << setiosflags(ios::fixed) << setprecision(2);
  int tc = 1;
  while (cin >> n && n) {
    cout << "**********************************************************" << endl;
    cout << "Network #" << tc << endl;
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < n; i++) {
      cin >> p[i].first >> p[i].second;
    }
    int mask = (1 << n) - 1;
    int start = -1, prev = -1;
    tsp(start + 1, mask);
    double tl = 0.0;
    for (int i = 0; i < n; i++) {
      prev = start;
      start = dp[start + 1][mask].second - 1;
      if (prev >= 0) {
        double l = point_dist(p[prev], p[start]) + 16.0;
        tl += l;
        cout << "Cable requirement to connect (" << p[prev].first << ','
             << p[prev].second << ") to (" << p[start].first << ','
             << p[start].second << ") is " << l << " feet." << endl;
      }
      mask &= ~(1 << start);
    }
    cout << "Number of feet of cable required is " << tl << '.' << endl;
    tc++;
  }
  return 0;
}
