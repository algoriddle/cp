#include <iostream>

using namespace std;

int alpha(char c) {
  if ('a' <= c && c <= 'z') {
    return c - 'a' + 1;
  }
  if ('A' <= c && c <= 'Z') {
    return c - 'A' + 1;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  for (string s; getline(cin, s) && s != "DONE"; ) {
    bool p = true;
    auto l = s.begin();
    auto r = s.end() - 1;
    while (l < r) {
      int ll = alpha(*l);
      if (!ll) {
        ++l;
        continue;
      }
      int rr = alpha(*r);
      if (!rr) {
        --r;
        continue;
      }
      if (ll != rr) {
        p = false;
        break;
      }
      ++l;
      --r;
    }
    if (p) {
      cout << "You won't be eaten!" << endl;
    } else {
      cout << "Uh oh.." << endl;
    }
  }
  return 0;
}
