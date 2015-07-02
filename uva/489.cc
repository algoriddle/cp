#include <array>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  array<int, 26> sm;
  while (1) {
    int r;
    cin >> r;
    if (r < 0) {
      break;
    }
    cout << "Round " << r << endl;
    string s, g;
    cin >> s >> g;
    sm.fill(0);
    for (char c : s) {
      sm[c - 'a']++;
    }
    int correct = 0;
    int incorrect = 0;
    for (char c : g) {
      c -= 'a';
      if (sm[c] > 0) {
        correct += sm[c];
        if (correct == s.size()) {
          break;
        }
        sm[c] = -1;
      } else if (sm[c] == 0) {
        incorrect++;
        if (incorrect == 7) {
          break;
        }
        sm[c] = -1;
      }
    }
    if (correct == s.size()) {
      cout << "You win." << endl;
    } else if (incorrect == 7) {
      cout << "You lose." << endl;
    } else {
      cout << "You chickened out." << endl;
    }
  }
  return 0;
}
