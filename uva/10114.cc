#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  while (1) {
    int duration, depreciation_count;
    double down_payment, amount;
    cin >> duration >> down_payment >> amount >> depreciation_count;
    if (duration < 0) {
      break;
    }
    double value[duration + 2]; // value at the beginning of ith month
    value[0] = down_payment + amount;
    int month = 0;
    double depreciation = 1.0;
    while (depreciation_count--) {
      int depreciation_month;
      double depreciation_value;
      cin >> depreciation_month >> depreciation_value;
      for (; month < depreciation_month; month++) {
        value[month + 1] = value[month] * depreciation;
      }
      depreciation = 1.0 - depreciation_value;
    }
    for (; month <= duration; month++) {
      value[month + 1] = value[month] * depreciation;
    }
    double payment = amount / duration;
    for (int i = 0; i <= duration; i++) {
      if (amount <= value[i + 1]) {
        cout << i << (i == 1 ? " month" : " months") << endl;
        break;
      }
      amount -= payment;
    }
  }
  return 0;
}
