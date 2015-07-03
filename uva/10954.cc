#include <iostream>
#include <algorithm>

using namespace std;

int heap[5000];

int main() {
  ios::sync_with_stdio(false);
  int n;
  while (cin >> n && n) {
    for (int i = 0; i < n; i++) {
      cin >> heap[i];
    }
    make_heap(heap, heap + n, greater<int>());
    int cost = 0;
    while (n > 1) {
      int s = heap[0];
      pop_heap(heap, heap + n, greater<int>());
      n--;
      s += heap[0];
      pop_heap(heap, heap + n, greater<int>());
      heap[n - 1] = s;
      push_heap(heap, heap + n, greater<int>());
      cost += s;
    }
    cout << cost << endl;
  }
  return 0;
}
