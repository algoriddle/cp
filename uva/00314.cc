#include <iostream>
#include <vector>
#include <bitset>
#include <tuple>
#include <queue>

using namespace std;

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  for (int R, C; cin >> R >> C && R && C; ) {
    vector<vector<bitset<5>>> v(R + 1, vector<bitset<5>>(C + 1));
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        int b;
        cin >> b;
        if (b) {
          v[r][c].set();
          v[r][c + 1].set();
          v[r + 1][c].set();
          v[r + 1][c + 1].set();
        }
      }
    }
    int br, bc, bd, er, ec;
    cin >> br >> bc >> er >> ec;
    string bds;
    cin >> bds;
    switch (bds[0]) {
      case 'n': bd = 0; break;
      case 'e': bd = 1; break;
      case 's': bd = 2; break;
      case 'w': bd = 3; break;
    }

    if (br == er && bc == ec) {
      cout << 0 << endl;
      continue;
    }
    if (v[er][ec].any()) {
      cout << -1 << endl;
      continue;
    }
    queue<tuple<int, int, int, int>> q;
    q.emplace(br, bc, bd, 0);
    v[br][bc].set(bd);
    bool found = false;
    while (!q.empty() && !found) {
      auto t = q.front(); q.pop();
      int tr = get<0>(t), tc = get<1>(t), td = get<2>(t), tl = get<3>(t);
      //cout << "FROM: " << tr << ' ' << tc << ' ' << td << ' ' << tl << endl;
      vector<tuple<int, int, int, int>> cs;
      cs.emplace_back(tr, tc, (td + 1) % 4, tl + 1);
      cs.emplace_back(tr, tc, (td + 3) % 4, tl + 1);
      for (int i = 1; i <= 3; ++i) {
        cs.emplace_back(tr + dr[td] * i, tc + dc[td] * i, td, tl + 1);
      }
      for (int i = 0; i < 5; ++i) {
        int cr = get<0>(cs[i]), cc = get<1>(cs[i]), cd = get<2>(cs[i]), cl = get<3>(cs[i]);;
        if (cr == er && cc == ec) {
          cout << cl << endl;
          found = true;
          break;
        }
        if (cr < 1 || cr >= R || cc < 1 || cc >= C) continue;
        if (v[cr][cc][cd]) {
          if (i > 1 && v[cr][cc][4]) break;
          else continue;
        }
        //cout << "TO: " << cr << ' ' << cc << ' ' << cd << ' ' << cl << endl;
        q.push(cs[i]);
        v[cr][cc].set(cd);
      }
    }
    if (!found) {
      cout << -1 << endl;
    }
  }
  return 0;
}
