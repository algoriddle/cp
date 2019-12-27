#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  string line;
  while (getline(cin, line))
  {
    for (auto &c : line) {
      c -= 7;
    }
    cout << line << endl;
  }
}
