#include <algorithm>
#include <array>
#include <iostream>

using namespace std;

int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
array<int, 401> year_to_day;
array<array<int, 12>, 2> month_to_day;

int is_leap_year(int y) {
  if (y % 4) {
    return false;
  }
  return y % 100 != 0 || y % 400 == 0;
}
  
int date_to_days(int d, int m, int y) {
  return (y / 400) * year_to_day[400] + year_to_day[y % 400]
    + month_to_day[is_leap_year(y)][m - 1] + d - 1;
}

void days_to_date(int o, int& d, int& m, int& y) {
  //cout << o << endl;
  y = (o / year_to_day[400]) * 400;
  o %= year_to_day[400];
  //cout << o << endl;
  int t = upper_bound(year_to_day.begin(), year_to_day.end(), o)
    - year_to_day.begin() - 1;
  y += t;
  o -= year_to_day[t];
  int l = is_leap_year(y);
  m = upper_bound(month_to_day[l].begin(), month_to_day[l].end(), o)
    - month_to_day[l].begin();
  d = o - month_to_day[l][m - 1] + 1;
}

int main() {
  ios::sync_with_stdio(false);
  year_to_day[0] = 0;
  year_to_day[1] = 366;
  for (int i = 2; i <= 400; i++) {
    year_to_day[i] = year_to_day[i - 1]
      + ((i % 4 == 1 && i % 100 != 1) ? 366 : 365);
    //cout << year_to_day[i] << endl;
  }
  month_to_day[0][0] = 0;
  month_to_day[1][0] = 0;
  for (int i = 1; i < 12; i++) {
      month_to_day[0][i] = month_to_day[0][i - 1] + months[i - 1];
      month_to_day[1][i] = month_to_day[1][i - 1] + months[i - 1];
      if (i == 2) {
        month_to_day[1][2]++;
      }
      //cout << month_to_day[0][i] << ' ' << month_to_day[1][i] << endl;
  }
  while (1) {
    int o, d, m, y;
    cin >> o >> d >> m >> y;
    if (!o && !d && !m && !y) {
      break;
    }
    days_to_date(date_to_days(d, m, y) + o, d, m, y);
    cout << d << ' ' << m << ' ' << y << endl;
  }
  return 0;
}
