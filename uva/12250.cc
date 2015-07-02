#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  unordered_map<string, string> map = {
    { "HELLO", "ENGLISH" },
    { "HOLA", "SPANISH" },
    { "HALLO", "GERMAN" },
    { "BONJOUR", "FRENCH" },
    { "CIAO", "ITALIAN" },
    { "ZDRAVSTVUJTE", "RUSSIAN" } };
  int i = 1;
  while (true) {
    string str;
    getline(cin, str);
    if (str == "#") {
      break;
    }
    cout << "Case " << i++ << ": ";
    auto ans = map.find(str);
    if (ans == map.end()) {
      cout << "UNKNOWN";
    } else {
      cout << ans->second;
    }
    cout << endl;
  }
  return 0;
}
