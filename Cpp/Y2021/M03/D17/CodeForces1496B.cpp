#include <bits/stdc++.h>

using namespace std;

int main() {
  int tests;
  cin >> tests;
  for (int t = 0; t < tests; ++t) {
    int n, k;
    cin >> n >> k;
    set<int> nums;
    for (int i = 0; i < n; ++i) {
      int tmp;
      cin >> tmp;
      nums.insert(tmp);
    }

    bool printing = true;
    int mexN = 0;
    while (nums.find(mexN) != nums.end()) ++mexN;
    int maxN;
    for (int i = 0; i < k; ++i) {
      maxN = *nums.rbegin();
      int newN = ceil((mexN + maxN) / 2.0);
      if (nums.find(newN) != nums.end()) {
        break;
      }
      if (newN == mexN) {
        printing = false;
        cout << nums.size() + k - i << endl;
        break;
      }
      nums.insert(newN);
      while (nums.find(mexN) != nums.end()) ++mexN;
    }
    if (printing) {
      cout << nums.size() << '\n';
    }
  }
}
