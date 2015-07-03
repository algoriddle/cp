#include <iostream>
#include <set>

using namespace std;

bool palindrome(const string& s) {
  string::const_iterator i = s.begin();
  string::const_iterator j = s.end() - 1;
  while (i < j) {
    if (*i != *j) {
      return false;
    }
    i++;
    j--;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  string s;
  while (cin >> s) {
    set<string> ps;
    int l = s.length();
    for (int i = 0; i < l; i++) {
      for (int j = 1; i + j <= l; j++) {
        string p = s.substr(i, j);
        if (palindrome(p)) {
          ps.insert(p);
        }
      }
    }
    cout << "The string '" << s << "' contains "
         << ps.size() <<  " palindromes." << endl;
  }
  return 0;
}
