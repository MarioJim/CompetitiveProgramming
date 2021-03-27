#include <bits/stdc++.h>

using namespace std;

int main() {
  int tests;
  cin >> tests;
  for (int t = 0; t < tests; ++t) {
    long long w1, w2, x1, x2, m;
    cin >> w1 >> w2 >> x1 >> x2 >> m;
    long long weightDelta = w2 - w1;
    if (weightDelta >= x1 * m && weightDelta <= x2 * m) {
      cout << "1\n";
    } else {
      cout << "0\n";
    }
  }
}
