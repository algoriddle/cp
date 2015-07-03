#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

typedef tuple<int, int, int> query;

int main() {
  ios::sync_with_stdio(false);
  string cmd;
  priority_queue<query, vector<query>, greater<query>> heap; 
  while (cin >> cmd && cmd != "#") {
    int n, p;
    cin >> n >> p;
    heap.push(query(p, n, p));
  }
  int k;
  cin >> k;
  while (k--) {
    query q = heap.top();
    heap.pop();
    cout << get<1>(q) << endl;
    heap.push(query(get<0>(q) + get<2>(q), get<1>(q), get<2>(q)));
  }
  return 0;
}
