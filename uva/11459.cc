#include <iostream>
#include <cstring>

using namespace std;

int players[1000000];
int board[101];

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    memset(players, 0, a * sizeof(int));
    memset(board, 0, sizeof board);
    while (b--) {
      int from, to;
      cin >> from >> to;
      board[from] = to;
    }
    int finished = false;
    for (int i = 0; i < c; i++) {
      int d;
      cin >> d;
      if (finished) {
        continue;
      }
      int p = i % a;
      players[p] = min(players[p] + d, 99);
      if (board[players[p] + 1] != 0) {
        players[p] = board[players[p] + 1] - 1;
      }
      if (players[p] == 99) {
        finished = true;
      }
    }
    for (int i = 0; i < a; i++) {
      cout << "Position of player " << i + 1
           << " is " << players[i] + 1 << '.' << endl;
    }
  }
  return 0;
}
