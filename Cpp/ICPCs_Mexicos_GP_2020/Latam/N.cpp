#include <bits/stdc++.h>

using namespace std;

int parseMoney(const std::string& moneyStr) {
  int result = 0;
  for (int i = 0; i < moneyStr.length(); ++i) {
    if (i == 0 || moneyStr[i] == '.') {
      continue;
    }
    result = result * 10 + (moneyStr[i] - '0');
  }
  return result;
}

int main() {
  int n;
  cin >> n;

  std::string inp;
  cin >> inp;
  int money = parseMoney(inp);

  int daysLate = 0;
  for (int i = 0; i < n; ++i) {
    cin >> inp;
    money += parseMoney(inp);
    if (money % 100 != 0) ++daysLate;
  }
  cout << daysLate << endl;

}
