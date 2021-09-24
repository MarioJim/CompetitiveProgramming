#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  long long result = -2;
  long long prod1 = 1;
  for (int i = 0; i < n; ++i) {
    prod1 *= 2;
  }
  long long prod2 = 1;
  for (int i = 0; i < m; ++i) {
    prod2 *= 2;
  }
  result += prod1 + prod2;
  cout << result << endl;
}
