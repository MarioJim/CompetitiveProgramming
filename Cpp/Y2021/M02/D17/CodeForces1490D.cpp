#include <bits/stdc++.h>

using namespace std;

int main() {
  int tests;
  cin >> tests;
  for (int t = 0; t < tests; ++t) {
    int n;
    cin >> n;
    int input[n];
    for (int i = 0; i < n; ++i) cin >> input[i];
    for (int i = 0; i < n; ++i) --input[i];

    int inputReversed[n];
    for (int i = 0; i < n; ++i) {
      inputReversed[input[i]] = i;
    }

    int height[n];
    fill(height, height + n, 0);
    for (int i = n - 1; i >= 0; --i) {
      int index = inputReversed[i];
      int fromIdx = index;
      while (fromIdx >= 0 && input[fromIdx] <= i) {
        --fromIdx;
      }
      int toIdx = index;
      while (toIdx < n && input[toIdx] <= i) {
        ++toIdx;
      }
      for (int j = fromIdx + 1; j < toIdx; ++j) {
        if (j != index) {
          ++height[j];
        }
      }
    }

    cout << height[0];
    for (int i = 1; i < n; ++i) {
      cout << ' ' << height[i];
    }
    cout << endl;
  }
}
