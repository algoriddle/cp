#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  priority_queue<long long> lower, upper;
  long long x;
  while (cin >> x) {
    if (lower.empty() || x < lower.top()) {
      lower.push(x);
    } else {
      upper.push(-x);
    }
    while (upper.size() > lower.size()) {
      lower.push(-upper.top());
      upper.pop();
    }
    while (upper.size() < lower.size() - 1) {
      upper.push(-lower.top());
      lower.pop();
    }
    if (lower.size() == upper.size()) {
      cout << (lower.top() - upper.top()) / 2 << endl;
    } else {
      cout << lower.top() << endl;
    }
  }
  return 0;
}
