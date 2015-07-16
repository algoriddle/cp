#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<string, string> ps;

int main() {
  ios::sync_with_stdio(false);
  vector<ps> w;
  for (string s; cin >> s && s != "#"; ) {
    string ss = s;
    transform(ss.begin(), ss.end(), ss.begin(), ::tolower);
    sort(ss.begin(), ss.end());
    w.emplace_back(ss, s);
  }
  sort(w.begin(), w.end(),
       [] (const ps& e1, const ps& e2) { return e1.first < e2.first; });
  int l = w.size() - 1;
  vector<string> r;
  for (int i = 0; i <= l; i++) {
    if ((i == 0 || w[i].first != w[i - 1].first)
        && (i == l || w[i].first != w[i + 1].first)) {
      r.push_back(w[i].second);
    }
  }
  sort(r.begin(), r.end());
  for (const string& s : r) {
    cout << s << endl;
  }
  return 0;
}
