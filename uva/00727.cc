#include <iostream>
#include <stack>

using namespace std;

//                   *  +  ,  -  .  /
int precedence[] = { 2, 1, 0, 1, 0, 2 };

int main() {
  ios::sync_with_stdio(false);
  bool first = true;
  int n;
  cin >> n;
  cin.ignore(2);
  while (n--) {
    if (!first) {
      cout << endl;
    }
    first = false;
    stack<char> st;
    while (1) {
      string line;
      getline(cin, line);
      if (line.length() > 0) {
        //cout << line << endl;
        char c = line[0];
        switch (c) {
        case '(':
          st.push(c);
          break;
        case ')':
          while (st.top() != '(') {
            cout << st.top();
            st.pop();
          }
          st.pop();
          break;
        case '+':
        case '-':
        case '*':
        case '/':
          while (!st.empty() && st.top() != '(' &&
                 precedence[st.top() - '*'] >= precedence[c - '*']) {
            cout << st.top();
            st.pop();
          }
          st.push(c);
          break;
        default:
          cout << c;
        }
      } else {
        while (!st.empty()) {
          if (st.top() != '(') {
            cout << st.top();
          }
          st.pop();
        }
        cout << endl;
        break;
      }
    }
  }
  return 0;
}
