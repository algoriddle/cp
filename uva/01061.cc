#include <iostream>
#include <set>
#include <vector>

using namespace std;

string abo_name[] = {"A", "B", "AB", "O"};
char rh_name[] = {'+', '-'};

int abo_add[3][3] = {{0, 2, 0},
                     {2, 1, 1},
                     {0, 1, 3}};

int rh_add(int i, int j) {
  return i == 1 && j == 1 ? 1 : 0;
}

vector<int> abo_split(string p) {
  if (p.length() > 2) {
    return { 0, 1 };
  }
  switch (p[0]) {
  case 'A': return { 0, 2 };
  case 'B': return { 1, 2 };
  case 'O': return { 2 };
  }
}

vector<int> rh_split(char r) {
  if (r == '+')
    return { 0, 1 };
  else
    return { 1 };
}

vector<int> abo_subtract(string c, int abo) {
  if (c.length() > 2) {
    if (abo < 2) {
      return { abs(abo - 1) };
    }
  } else {
    switch (c[0]) {
    case 'A': if (abo == 0) return { 0, 2 }; else if (abo == 2) return { 0 }; else break;
    case 'B': if (abo == 1) return { 1, 2 }; else if (abo == 2) return { 1 }; else break;
    case 'O': if (abo == 2) return { 2 }; else break;
    }
  }
  return { };
}

vector<int> abo_possible(int p) {
  switch (p) {
  case 0: return {0, 2};
  case 1: return {1, 2};
  case 2: return {0, 1, 3};
  }
}

void print(const set<string>& r) {
  if (r.size() > 1) {
    cout << '{';
    bool first = true;
    for (string s : r) {
      if (!first) {
        cout << ", ";
      }
      first = false;
      cout << s;
    }
    cout << '}';
  } else {
    for (string s : r) {
      cout << s;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  int caseno = 1;
  while (1) {
    string p1, p2, c;
    cin >> p1 >> p2 >> c;
    if (p1[0] == 'E') {
      break;
    }
    cout << "Case " << caseno << ": ";
    caseno++;
    if (c[0] == '?') {
      set<string> result;
      for (int p1abo : abo_split(p1)) {
        for (int p2abo : abo_split(p2)) {
          for (int p1rh : rh_split(p1[p1.length() - 1])) {
            for (int p2rh : rh_split(p2[p2.length() - 1])) {
              result.insert(abo_name[abo_add[p1abo][p2abo]] + rh_name[rh_add(p1rh, p2rh)]);
            }
          }
        }
      }
      cout << p1 << ' ' << p2 << ' ';
      print(result);
      cout << endl;
    } else {
      string p = p1[0] == '?' ? p2 : p1;
      set<string> result;
      for (int abo : abo_split(p)) {
        for (int cabo : abo_subtract(c, abo)) {
          for (int pabo : abo_possible(cabo)) {
            result.insert(abo_name[pabo] + '+');
            if (c[c.length() - 1] != '+' || p[p.length() - 1] != '-') {
              result.insert(abo_name[pabo] + '-');
            }
          }
        }
      }
      if (p1[0] != '?') {
        cout << p1 << ' ';
      }
      if (result.size() == 0) {
        cout << "IMPOSSIBLE";
      } else {
        print(result);
      }
      if (p2[0] != '?') {
        cout << ' ' << p2;
      }
      cout << ' ' << c << endl;
    }
  }
  return 0;
}
