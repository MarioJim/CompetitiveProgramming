#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, tmp;
  cin >> n >> m;
  long long balance = 0;
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    balance -= tmp;
  }
  for (int i = 0; i < m; ++i) {
    cin >> tmp;
    balance += tmp;
  }
  cout << balance << '\n';
}
