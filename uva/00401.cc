#include <iostream>
#include <cstring>

using namespace std;

int cm[256];

int main() {
  ios::sync_with_stdio(false);
  memset(cm, 0, sizeof cm);
  cm[static_cast<unsigned>('A')] = 'A';
  cm[static_cast<unsigned>('E')] = '3';
  cm[static_cast<unsigned>('H')] = 'H';
  cm[static_cast<unsigned>('I')] = 'I';
  cm[static_cast<unsigned>('J')] = 'L';
  cm[static_cast<unsigned>('L')] = 'J';
  cm[static_cast<unsigned>('M')] = 'M';
  cm[static_cast<unsigned>('S')] = '2';
  cm[static_cast<unsigned>('T')] = 'T';
  cm[static_cast<unsigned>('U')] = 'U';
  cm[static_cast<unsigned>('V')] = 'V';
  cm[static_cast<unsigned>('W')] = 'W';
  cm[static_cast<unsigned>('X')] = 'X';
  cm[static_cast<unsigned>('Y')] = 'Y';
  cm[static_cast<unsigned>('Z')] = '5';
  cm[static_cast<unsigned>('O')] = 'O';
  cm[static_cast<unsigned>('1')] = '1';
  cm[static_cast<unsigned>('2')] = 'S';
  cm[static_cast<unsigned>('3')] = 'E';
  cm[static_cast<unsigned>('5')] = 'Z';
  cm[static_cast<unsigned>('8')] = '8';
  string s;
  while (cin >> s) {
    bool p = true, m = true;
    auto left = s.begin();
    auto right = s.end() - 1;
    while (left <= right && (p || m)) {
      if (*left != *right) {
        p = false;
      }
      if (cm[static_cast<unsigned>(*left)] != *right) {
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
