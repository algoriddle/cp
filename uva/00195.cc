#include <algorithm>
#include <iostream>

using namespace std;

bool comp(const char& c1, const char& c2) {
  char lc1 = tolower(c1);
  char lc2 = tolower(c2);
  return lc1 == lc2 ? c1 < c2 : lc1 < lc2;
}

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    sort(s.begin(), s.end(), comp);
    do {
      cout << s << endl;
    } while (next_permutation(s.begin(), s.end(), comp));
  }
  return 0;
}
