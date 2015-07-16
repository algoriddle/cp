#include <iostream>
#include <cstring>

using namespace std;

int cm[256];

int main() {
  ios::sync_with_stdio(false);
  memset(cm, 0, sizeof cm);
  cm['A'] = 'A';
  cm['E'] = '3';
  cm['H'] = 'H';
  cm['I'] = 'I';
  cm['J'] = 'L';
  cm['L'] = 'J';
  cm['M'] = 'M';
  cm['S'] = '2';
  cm['T'] = 'T';
  cm['U'] = 'U';	
  cm['V'] = 'V';
  cm['W'] = 'W';	
  cm['X'] = 'X';
  cm['Y'] = 'Y';
  cm['Z'] = '5';
  cm['O'] = 'O';
  cm['1'] = '1';
  cm['2'] = 'S';
  cm['3'] = 'E';
  cm['5'] = 'Z';
  cm['8'] = '8';
  string s;
  while (cin >> s) {
    bool p = true, m = true;
    auto left = s.begin();
    auto right = s.end() - 1;
    while (left <= right && (p || m)) {
      if (*left != *right) {
        p = false;
      }
      if (cm[*left] != *right) {
        m = false;
      }
      ++left;
      --right;
    }
    cout << s;
    if (p && m) {
      cout << " -- is a mirrored palindrome.";
    } else if (p) {
      cout << " -- is a regular palindrome.";
    } else if (m) {
      cout << " -- is a mirrored string.";
    } else {
      cout << " -- is not a palindrome.";
    }
    cout << endl << endl;
  }
}
