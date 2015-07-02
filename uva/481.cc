#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  vector<int> numbers;
  vector<int> links;
  vector<int> ends;
  vector<int> endidxs;
  int x;
  while (cin >> x) {
    numbers.push_back(x);
    auto i = lower_bound(ends.begin(), ends.end(), x);
    if (i == ends.end()) {
      ends.push_back(x);
      if (endidxs.empty()) {
        links.push_back(-1);
      } else {
        links.push_back(endidxs.back());
      }
      endidxs.push_back(numbers.size() - 1);
    } else {
      *i = x;
      if (i == ends.begin()) {
        links.push_back(-1);
      } else {
        links.push_back(endidxs[i - ends.begin() - 1]);
      }
      endidxs[i - ends.begin()] = numbers.size() - 1;
    }
    /*
    copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(links.begin(), links.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(ends.begin(), ends.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(endidxs.begin(), endidxs.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    */
  }
  int l = ends.size();
  cout << l  << endl;
  cout << '-' << endl;
  if (l == 0) {
    return 0;
  }
  int r[l];
  int i = endidxs.back();
  while (l--) {
    r[l] = numbers[i];
    //cout << l << ' ' << i << ' ' << numbers[i] << endl;
    i = links[i];
  }
  for (auto x : r) {
    cout << x << endl;
  }
  return 0;
}
