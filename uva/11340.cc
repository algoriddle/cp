#include <iostream>
#include <cstring>
#include <iomanip>
#include <limits>

using namespace std;

int t[256];

int main() {
  ios::sync_with_stdio(false);
  cout << setiosflags(ios::fixed) << setprecision(2);
  int q;
  cin >> q;
  //cout << q << endl;
  while (q--) {
    int k;
    cin >> k;
    //cout << k << endl;
    memset(t, 0, sizeof t);
    cin.ignore();
    while (k--) {
      unsigned char c = cin.get();
      int v;
      cin >> v;
      t[c] = v;
      cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
      //cout << c << ' ' << v << endl;
    }
    int m;
    cin >> m;
    cin.ignore();
    long long total = 0;
    while (m--) {
      string line;
      getline(cin, line);
      //cout << line << endl;
      for (unsigned char c : line) {
        total += t[c];
      }
    }
    cout << (double)total / 100.0L << '$' << endl;
  }
  return 0;
}
