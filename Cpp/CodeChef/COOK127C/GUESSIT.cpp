#include <bits/stdc++.h>

using namespace std;

int main() {
  int tests;
  cin >> tests;
  for (int t = 0; t < tests; ++t) {
    for (int i = 1; i < 1001; ++i) {
      cout << i * i << endl;
      int resp;
      cin >> resp;
      if (resp == 1)
        break;
    }
  }
}
