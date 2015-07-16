#include <iostream>

using namespace std;

int k, x[12], i[6];

#define FOR(x, s) for (x = s; x < k; x++)

int main() {
  bool first = true;
  ios::sync_with_stdio(false);
  while (cin >> k && k) {
    for (int i = 0; i < k; i++) {
      cin >> x[i];
    }
    if (!first) {
      cout << endl;
    }
    first = false;
    FOR(i[0], 0) {
      FOR(i[1], i[0] + 1) {
        FOR(i[2], i[1] + 1) {
          FOR(i[3], i[2] + 1) {
            FOR(i[4], i[3] + 1) {
              FOR(i[5], i[4] + 1) {
                for (int j = 0; j < 5; j++) {
                  cout << x[i[j]] << ' ';
                }
                cout << x[i[5]] << endl;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
