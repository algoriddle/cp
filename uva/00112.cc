#include <iostream>
//#include <cassert>

using namespace std;

int rtl(int sum, bool op) {
  string d;
  char c;
  if (op) {
    cin >> c;
    //assert(c == '(');
  }
  while (1) {
    cin >> c;
    if (c == '-' || ('0' <= c && c <= '9')) {
      d.push_back(c);
    } else {
      break;
    }
  }
  if (d.empty()) return 0;
  sum -= stoi(d);
  int left = rtl(sum, false);
  int right = rtl(sum, true);
  cin >> c;
  //assert(c == ')');
  return (left == 1 || right == 1 || (left == 0 && right == 0 && sum == 0)) ? 1 : -1;
}

int main() {
  ios::sync_with_stdio(false);
  for (int sum; cin >> sum; ) {
    cout << (rtl(sum, true) == 1 ? "yes" : "no") << endl;
  }
  return 0;
}
