#include <bits/stdc++.h>

using namespace std;

int main() {
  int tests;
  cin >> tests;
  for (int t = 0; t < tests; ++t) {
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; ++i) cin >> nums[i];
    sort(nums, nums + n);

    int foundUntil = 0;
    vector<int> otherNums;
    for (int i = 0; i < n; ++i) {
      if (foundUntil == nums[i]) {
        ++foundUntil;
      } else {
        otherNums.emplace_back(nums[i]);
      }
    }

    if (otherNums.empty()) {
      for (int i = 0; i < foundUntil - 1; ++i) {
        cout << i << ' ';
      }
      cout << foundUntil - 1 << endl;
    } else {
      for (int i = 0; i < foundUntil; ++i) {
        cout << i << ' ';
      }
      for (int i = 0; i < otherNums.size() - 1; ++i) {
        cout << otherNums[i] << ' ';
      }
      cout << *otherNums.rbegin() << endl;
    }
  }
}
