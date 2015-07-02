#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int rfp = 1;
  while (1) {
    int n, p;
    cin >> n >> p;
    if (n == 0) {
      break;
    }
    int i = n + 1;
    while (i--) {
      cin.ignore(100, '\n');
    }
    string rpn;
    double rpp;
    int rpr = -1;    
    for (i = 0; i < p; i++) {
      string pn;
      double pp;
      int pr;
      getline(cin, pn);
      cin >> pp >> pr;
      int j = pr + 1;
      while (j--) {
        cin.ignore(100, '\n');
      }
      //cout << pn << endl << pp << endl << pr << endl;
      if (pr > rpr
          || (pr == rpr && pp < rpp)) {
        rpn = pn;
        rpp = pp;
        rpr = pr;
      }
    }
    if (rfp > 1) {
      cout << endl;
    }
    cout << "RFP #" << rfp++ << endl;
    cout << rpn << endl;
  }
  return 0;
}
