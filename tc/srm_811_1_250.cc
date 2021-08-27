#include <iostream>

#include <vector>

using namespace std;

class ReconstructPermutation {
public:
  vector<int> reconstruct(int N, vector<int> partial) {
    vector<int> r;
    vector<bool> m(N);
    for (auto x : partial) {
      m[x] = true;
    }
    auto i = 0;
    for (auto x : partial) {
      for (; i < x; i++) {
        if (!m[i]) {
          r.push_back(i);
        }
      }
      r.push_back(x);
    }
    for (; i < N; i++) {
      if (!m[i]) {
        r.push_back(i);
      }
    }
    return r;
  }
};

int main() {
  ReconstructPermutation c;
  auto r = c.reconstruct(5, {5, 1});
  for (auto x : r) {
    cout << x << ' ';
  }
  cout << endl;
}
