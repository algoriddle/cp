#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class union_find {
public:
  union_find(int n) :p(n), h(n, 0) {
    for (int i = 0; i < n; i++) {
      p[i] = i;
    }
  }

  void connect(int a, int b) {
    int ra = root(a), rb = root(b);
    if (ra != rb) {
      if (h[ra] > h[rb]) {
        p[rb] = ra;
      } else {
        p[ra] = rb;
        if (h[ra] == h[rb]) {
          h[rb]++;
        }
      }
    }
  }

  bool same(int a, int b) {
    return root(a) == root(b);
  }
  
private:
  int root(int x) {
    return p[x] == x ? x : p[x] = root(p[x]);
  }
  
  vector<int> p;
  vector<int> h;
};

int main() {
  ios::sync_with_stdio(false);
  int tc;
  cin >> tc;
  for (int t = 0; t < tc; t++) {
    int n;
    cin >> n;
    cin.ignore();
    int succ = 0, fail = 0;
    union_find uf(n);
    for (string s; getline(cin, s) && !s.empty(); ) {
      stringstream ss(s);
      char o;
      ss >> o;
      int a, b;
      ss >> a >> b;
      --a; --b;
      switch (o) {
      case 'c':
        uf.connect(a, b);
        break;
      case 'q':
        if (uf.same(a, b)) {
          ++succ;
        } else {
          ++fail;
        }
        break;
      }
    }
    if (t > 0) {
      cout << endl;
    }
    cout << succ << ',' << fail << endl;
  }
  return 0;
}
