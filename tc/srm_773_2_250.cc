#include <iostream>

#include <vector>

using namespace std;

class ChristmasCrackers {
public:
  vector<int> crack(int N, int K) {
    vector<int> r;
    int c = N * K;
    c = c % 2 ? c + 1 : c;
    for (int i = 0; i < c; ++i) {
      r.push_back(i % N);
    }
    return r;
  }
};

int main() {
  ChristmasCrackers c;
  auto r = c.crack(5, 1);
  for (auto x : r) {
    cout << x << ' ';
  }
  cout << endl;
}
