#include <iostream>
#include <iterator>

using namespace std;

const int max_cars = 2001;

int x[max_cars], lis[max_cars], lds[max_cars];

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int lis_size = 0, lds_size = 0, max_train = 0;
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    while (n--) {
      int i = lower_bound(lis, lis + lis_size, x[n]) - lis;
      lis[i] = x[n];
      lis_size = max(lis_size, i + 1);
      int j = lower_bound(lds, lds + lds_size, -x[n]) - lds;
      lds[j] = -x[n];
      lds_size = max(lds_size, j + 1);
      //cout << i << endl;
      //copy(lis, lis + lis_size, ostream_iterator<int>(cout, " "));
      //cout << endl;
      //cout << j << endl;
      //copy(lds, lds + lds_size, ostream_iterator<int>(cout, " "));
      //cout << endl;
      max_train = max(max_train, i + j + 1);
    }
    cout << max_train << endl;
  }
  return 0;
}
