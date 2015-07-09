#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int c = 1; c <= t; c++) {
    int n;
    cin >> n;
    int h[n];
    for (int i = 0; i < n; i++) {
      cin >> h[i];
    }
    int w[n];
    for (int i = 0; i < n; i++) {
      cin >> w[i];
    }
    int global_inc = 0, global_dec = 0, dp_inc[n], dp_dec[n];
    for (int i = 0; i < n; i++) {
      int local_inc = 0;
      int local_dec = 0;
      for (int j = 0; j < i; j++) {
        if (h[j] < h[i]) {
          local_inc = max(local_inc, dp_inc[j]);
        }
        if (h[j] > h[i]) {
          local_dec = max(local_dec, dp_dec[j]);
        }
      }
      dp_inc[i] = local_inc + w[i];
      dp_dec[i] = local_dec + w[i];
      global_inc = max(global_inc, dp_inc[i]);
      global_dec = max(global_dec, dp_dec[i]);
    }
    cout << "Case " << c;
    if (global_inc >= global_dec) {
      cout << ". Increasing (" << global_inc << "). Decreasing (" << global_dec;
    } else {
      cout << ". Decreasing (" << global_dec << "). Increasing (" << global_inc;
    }
    cout << ")." << endl; 
  }
  return 0;
}
