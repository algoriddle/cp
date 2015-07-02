#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  bool first = true;
  int t;
  cin >> t;
  string s;
  getline(cin, s);
  getline(cin, s);
  while (t--) {
    vector<string> m;
    while (getline(cin, s)) {
      if (s.empty()) {
        break;
      } else {
        m.push_back(s);
      }
    }
    int r = m.size();
    int c = m[0].length();
    int h[c];
    memset(h, 0, sizeof h);
    int max_area = 0;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        h[j] = m[i][j] == '0' ? 0 : h[j] + 1;
      }
      stack<int> stack;
      int k = 0;
      while (k < c || !stack.empty()) {
        if (k < c && (stack.empty() || h[k] >= h[stack.top()])) {
          stack.push(k);
          k++;
        } else {
          int height = h[stack.top()];
          stack.pop();
          int left = stack.empty() ? 0 : stack.top() + 1;
          int area = (k - left) * height;
          max_area = max(max_area, area);
        }
      }
    }
    if (!first) {
      cout << endl;
    }
    first = false;
    cout << max_area << endl;
  }
  return 0;
}
