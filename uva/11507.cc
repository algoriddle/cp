#include <iostream>

using namespace std;

string dn[] = { "+x", "-x", "+y", "-y", "+z", "-z" };
int dt[][6] = { { 2, 3, 1, 0, 4, 5 },
               { 3, 2, 0, 1, 4, 5 },
               { 4, 5, 2, 3, 1, 0 },
               { 5, 4, 2, 3, 0, 1 } };

int main() {
  ios::sync_with_stdio(false);
  while (1) {
    int l;
    cin >> l;
    if (l == 0) {
      break;
    }
    int d = 0;
    while (--l) {
      string bs;
      cin >> bs;
      int b;
      switch (bs[1])
        {
        case 'y': b = 0; break;
        case 'z': b = 2; break;
        default: continue;
        }
      if (bs[0] == '-') {
        b++;
      }
      d = dt[b][d];
    }
    cout << dn[d] << endl;
  }
  return 0;
}
