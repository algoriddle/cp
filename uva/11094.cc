#include <iostream>
#include <vector>

using namespace std;

int M, N, area;
vector<string> map;
char l;
int rs[] = {-1, 0, 1, 0};
int cs[] = {0, -1, 0, 1};

void fill(int r, int c) {
  if (r < 0 || r >= M) return;
  if (c < 0) c = N - 1;
  else if (c >= N) c = 0;
  if (map[r][c] != l) return;
  map[r][c] = l + 1;
  ++area;
  for (int i = 0; i < 4; ++i) {
    fill(r + rs[i], c + cs[i]);
  }
}

int main() {
  ios::sync_with_stdio(false);
  while (cin >> M >> N) {
    map.resize(M);
    for (int i = 0; i < M; ++i) {
      cin >> map[i];
    }
    int R, C;
    cin >> R >> C;
    l = map[R][C];
    area = 0;
    fill(R, C);
    int max_area = 0;
    for (int r = 0; r < M; ++r) {
      for (int c = 0; c < N; ++c) {
        area = 0;
        fill(r, c);
        max_area = max(max_area, area);
      }
    }
    cout << max_area << endl;
  }
  return 0;
}
