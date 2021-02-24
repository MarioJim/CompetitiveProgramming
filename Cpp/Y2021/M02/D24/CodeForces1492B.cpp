#include <bits/stdc++.h>

using namespace std;

int main() {
  int tests;
  cin >> tests;
  for (int t = 0; t < tests; ++t) {
    int n;
    cin >> n;
    vector<int> input;
    input.reserve(n);
    int inputReversed[n];
    for (int i = 0; i < n; ++i) {
      int tmp;
      cin >> tmp;
      input.push_back(tmp);
      inputReversed[tmp - 1] = i;
    }

    vector<int> result;
    result.reserve(n);
    int lastMoveOffset = n;
    for (int i = n - 1; i >= 0; --i) {
      int offset = inputReversed[i];
      if (offset > lastMoveOffset) continue;
      lastMoveOffset = offset;
      result.insert(result.end(), input.begin() + offset, input.end());
      input.erase(input.begin() + offset, input.end());
    }

    cout << result[0];
    for (int i = 1; i < n; ++i) cout << ' ' << result[i];
    cout << endl;
  }
}
