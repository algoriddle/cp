#include <iostream>
#include <cstring>

using namespace std;

int primes[11] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
bool is_prime[32];

int n, p[17], r[17];

void place(int k) {
  if (k > n) {
    if (!is_prime[r[1] + r[n]]) {
      return;
    }
    for (int i = 1; i <= n; i++) {
      if (i > 1) {
        cout << ' ';
      }
      cout << r[i];
    }
    cout << endl;
    return;
  }
  for (int i = 2; i <= n; i++) {
    if (p[i] == 0 && is_prime[i + r[k - 1]]) {
      r[k] = i;
      p[i] = k;
      place(k + 1);
      p[i] = 0;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  memset(is_prime, 0, sizeof is_prime);
  for (int i = 0; i < 11; i++) {
    is_prime[primes[i]] = true;
  }
  for (int c = 1; cin >> n; c++) {
    memset(p, 0, sizeof p);
    memset(r, 0, sizeof r);
    p[1] = 1;
    r[1] = 1;
    if (c > 1) {
      cout << endl;
    }
    cout << "Case " << c << ':' << endl;
    place(2);
  }
  return 0;
}
