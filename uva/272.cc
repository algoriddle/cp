#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin >> noskipws;
  bool first = true;
  char c;
  while (cin >> c) {
    if (c == '"') {
      cout << (first ? "``" : "''");
      first = !first;
    } else {
      cout << c;
    }
  }
  return 0;
}
