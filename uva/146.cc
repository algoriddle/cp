#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  string s;
  while (cin >> s && s != "#") {
    if (next_permutation(s.begin(), s.end())) {
      cout << s << endl;
    } else {
      cout << "No Successor" << endl;
    }
  }
  return 0;
}

