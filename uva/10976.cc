#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  for (int k; cin >> k; ) {
    int m = k << 1;
    vector<string> r;
    for (int y = k + 1; y <= m; y++) {
      int yk = y * k;
      int ymk = y - k;
      int x = y * k / (y - k);
      if (x * ymk == yk) {
        stringstream ss;
        ss << "1/" << k << " = 1/" << x << " + 1/" << y;
        r.push_back(ss.str());
      }
    }
    cout << r.size() << endl;
    for (auto s : r) {
      cout << s << endl;
    }
  }
  return 0;
}
