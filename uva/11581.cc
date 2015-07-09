#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int m[3], mm[3], c = 0;
    for (int i = 0; i < 3; i++) {
      string s;
      cin >> s;
      m[i] = stoi(s, 0, 2);
    }
    while (m[0] || m[1] || m[2]) {
      mm[0] = m[1];
      mm[1] = m[0] ^ m[2];
      mm[2] = m[1];
      for (int i = 0; i < 3; i++) {
        m[i] = mm[i] ^ ((m[i] << 1) & 7) ^ (m[i] >> 1);
      }
      c++;
    }
    cout << c - 1 << endl;
  }
  return 0;
}
