#include <iostream>
#include <vector>
using namespace std;

void printv(const vector<int> &v) {
  for (auto x : v) {
    cout << x << ' ';
  }
  cout << endl;
}

//--
#include <algorithm>
#include <vector>

using namespace std;

class ChristmasPudding {
public:
  long long eat(
    int N, long long Vall, long long Vsweet,
    vector<int> V, vector<int> T, vector<int> S, int seed)
  {
    long long state = seed;
    while (V.size() < N) {
      state = (state * 1103515245 + 12345) % 0x80000000;
      V.push_back(1 + (state % 1000000));
      state = (state * 1103515245 + 12345) % 0x80000000;
      T.push_back(1 + (state % 1000000));
      state = (state * 1103515245 + 12345) % 0x80000000;
      S.push_back((state / 1024) % 2);
    }
    //printv(V);
    //printv(T);
    //printv(S);
    
    //sum(X) = min(Vall, sum(V))
    //sum(X * S) >= min(Vsweet, sum(V * S))
    //max(X * T)
    //0 <= X <= V

    vector<pair<long long, int>> heap[2];
    heap[0].reserve(N);
    heap[1].reserve(N);
    long long sumV = 0, sumVS = 0;
    for (int i = 0; i < N; ++i) {
      sumV += V[i];
      sumVS += V[i] * S[i];
      heap[S[i]].push_back(make_pair(T[i], i));
    }
    
    make_heap(heap[0].begin(), heap[0].end());
    make_heap(heap[1].begin(), heap[1].end());
    Vall = min(Vall, sumV);
    Vsweet = min(Vsweet, sumVS);
    
    long long total = 0;
    while (Vsweet) {
      auto s = heap[1].front();
      int v = min(Vsweet, (long long)V[s.second]);
      V[s.second] -= v;
      if (V[s.second] == 0) {
        pop_heap(heap[1].begin(), heap[1].end());
        heap[1].pop_back();
      }
      Vsweet -= v;
      Vall -= v;
      total += s.first * v;
    }
    while (Vall) {
      pair<long long, int> s[2];
      s[0] = heap[0].empty() ? make_pair((long long)-1, -1) : heap[0].front();
      s[1] = heap[1].empty() ? make_pair((long long)-1, -1) : heap[1].front();
      int w = s[0].first < s[1].first;
      pop_heap(heap[w].begin(), heap[w].end());
      heap[w].pop_back();
      long long v = min(Vall, (long long)V[s[w].second]);
      Vall -= v;
      total += s[w].first * v;
    }
    return total;
  }
};
//--

int main() {
  ChristmasPudding c;
  cout << c.eat(3, 300, 220, {100, 100, 200}, {4, 5, 7}, {1, 0, 1}, 47) << endl;
  cout << c.eat(3, 390, 220, {100, 100, 200}, {4, 5, 7}, {1, 0, 1}, 4747) << endl;
  cout << c.eat(3, 300, 300, {100, 200, 300}, {30, 10, 20}, {0, 1, 0}, 42) << endl;
  cout << c.eat(2, 100, 0, {47, 10}, {3, 5}, {0, 0}, 5) << endl;
  cout << c.eat(20, 5000000, 3000000, {470}, {407}, {0}, 4747) << endl;
  cout << c.eat(10, 0, 0, {}, {}, {}, 0) << endl;
  return 0;
}
