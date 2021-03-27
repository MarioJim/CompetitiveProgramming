#include <bits/stdc++.h>

using namespace std;

int main() {
  int tests;
  cin >> tests;
  for (int t = 0; t < tests; ++t) {
    long long n;
    cin >> n;
    long long remCount[3] = {0, 0, 0};
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      ++remCount[a % 3];
    }
    long long shouldBe = n / 3;
    long long result = 0;
    while (true) {
      for (int i = 0; i < 3; ++i) {
        if (remCount[i] > shouldBe) {
          long long diff = remCount[i] - shouldBe;
          result += diff;
          remCount[i] -= diff;
          remCount[(i+1) % 3] += diff;
        }
      }
      if (remCount[0] == shouldBe && remCount[1] == shouldBe && remCount[2] == shouldBe)
        break;
    }
    cout << result << endl;
  }
}