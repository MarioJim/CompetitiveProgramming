#include <bits/stdc++.h>

using namespace std;

int main() {
  int tests;
  cin >> tests;
  for (int t = 0; t < tests; ++t) {
    int n, k;
    cin >> n >> k;
    string word;
    cin >> word;
    if (2 * k + 1 > n) {
      cout << "NO\n";
      continue;
    }
    bool yes = true;
    for (int i = 0; i < k; ++i) {
      if (word[i] != word[n-i-1]) {
        cout << "NO\n";
        yes = false;
        break;
      }
    }
    if (yes) {
      cout << "YES\n";
    }
  }
}
