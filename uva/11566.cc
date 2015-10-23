#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int N, X, T, K;
int price[100];
int flavor[100];
int memo[100][101][1001];

int service(int x) {
  int r = x + x / 10;
  if (x % 10) ++r;
  return r;
}

int opt(int current, int open, int spent) {
  if (current == K) return 0;
  if (memo[current][open][spent])
    return memo[current][open][spent] - 1;
  int r = 0;
  for (int i = min(open, 2); i >= 0; --i) {
    int ns = spent + price[current] * i;
    if (service(ns) <= X) {
      r = max(r, opt(current + 1, open - i, ns) + flavor[current] * i);
    }
  }
  memo[current][open][spent] = r + 1;
  return r;
}

int main() {
  ios::sync_with_stdio(false);
  cout << setiosflags(ios::fixed) << setprecision(2);
  while (cin >> N >> X >> T >> K && (N || X || T || K)) {
    ++N;
    X *= N;
    T *= N;
    for (int i = 0; i < K; ++i) {
      cin >> price[i];
      flavor[i] = 0;
      for (int j = 0; j < N; ++j) {
        int f;
        cin >> f;
        flavor[i] += f;
      }
    }
    memset(memo, 0, sizeof memo);
    cout << double(opt(0, min(K * 2, N * 2), T)) / N << endl;
  }
  return 0;
}
