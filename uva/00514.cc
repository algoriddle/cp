#include <iostream>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n;
  while (cin >> n && n) {
    int c[n];
    while (1) {
      stack<int> station;
      for (int i = 0; i < n; i++) {
        cin >> c[i];
        if (c[i] == 0) {
          break;
        }
      }
      if (c[0] == 0) {
        break;
      }
      int j = 1;
      for (int i = 0; i < n; i++) {
        while (c[i] >= j) {
          station.push(j);
          j++;
        }
        if (!station.empty() && c[i] == station.top()) {
          station.pop();
        } else {
          break;
        }
      }
      cout << (station.empty() ? "Yes" : "No") << endl;
    }
    cout << endl;
  }
}
