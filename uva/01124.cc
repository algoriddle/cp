//#include <iterator>
//#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  /*
  cin >> noskipws;
  copy(istreambuf_iterator<char>(cin),
       istreambuf_iterator<char>(),
       ostreambuf_iterator<char>(cout));
  */
  cout << cin.rdbuf();
  return 0;
}
