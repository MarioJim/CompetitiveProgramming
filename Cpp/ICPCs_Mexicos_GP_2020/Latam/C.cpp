#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  int tablesClock[n];
  int tablesAnti[n];
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> tablesClock[i];
    tablesAnti[i] = tablesClock[i];
    sum += tablesClock[i];
  }
  long long should = sum / n;
  int clock= 0, clockCurr = 0;
  int anti = 0, antiCurr = 0;
  for (int i = 0; i < 2 * n; ++i) {
    int posClock = i % n;
    int diffClock = (tablesClock[posClock] > should && tablesClock[posClock] - should > clockCurr) ? tablesClock[posClock] - should : clockCurr;
    tablesClock[posClock] -= diffClock;
    clockCurr += diffClock;
    clock += clockCurr;

    int posAnti = (2 * n - i) % n;
    int diffAnti = (tablesAnti[posAnti] > should && tablesAnti[posAnti] - should > antiCurr) ? tablesAnti[posAnti] - should : antiCurr;
    tablesAnti[posAnti] -= diffAnti;
    antiCurr += diffAnti;
    anti += antiCurr;
  }

  cout << min(clock, anti) << endl;
}
