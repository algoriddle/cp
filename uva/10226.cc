#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cout << setiosflags(ios::fixed) << setprecision(4);
  bool first = true;
  int n;
  cin >> n;
  cin.ignore(2);
  while (n--) {
    if (!first) {
      cout << endl;
    }
    first = false;
    int total = 0;
    map<string, int> trees;
    while (1) {
      string line;
      getline(cin, line);
      if (line.length() == 0) {
        break;
      }
      total++;
      auto i = trees.find(line);
      if (i == trees.end()) {
        trees[line] = 1;
      } else {
        i->second++;
      }
    }
    for (const auto& i : trees) {
      cout << i.first << ' '
           << 100.0L * (double)i.second / (double)total << endl;
    }
  }
  return 0;
}
