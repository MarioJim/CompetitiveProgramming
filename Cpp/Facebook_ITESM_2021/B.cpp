#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int r, c;
    cin >> r >> c;
    bool matrix[r][c];
    for (int j = 0; j < r; ++j) {
      for (int k = 0; k < c; ++k) {
        int x;
        cin >> x;
        matrix[j][k] = x == 1;
      }
    }

    int max_found = 0, m, n;
    for (int j = 0; j < r; ++j) {
      for (int k = 0; k < c; ++k) {
        if (matrix[j][k]) {
          int found = 0;
          std::queue<std::tuple<int, int>> q;
          q.push({j, k});
          while (!q.empty()) {
            std::tie(m, n) = q.front();
            q.pop();
            if (!matrix[m][n]) continue;
            matrix[m][n] = false;
            ++found;
            if (m < r-1 && n < c-1 && matrix[m + 1][n + 1]) q.push({m + 1, n + 1});
            if (m < r-1 && n > 0 && matrix[m + 1][n - 1]) q.push({m + 1, n - 1});
            if (m > 0 && n < c-1 && matrix[m - 1][n + 1]) q.push({m - 1, n + 1});
            if (m > 0 && n > 0 && matrix[m - 1][n - 1]) q.push({m - 1, n - 1});
            if (m < r-1 && matrix[m + 1][n]) q.push({m + 1, n});
            if (m > 0 && matrix[m - 1][n]) q.push({m - 1, n});
            if (n < c-1 && matrix[m][n + 1]) q.push({m, n + 1});
            if (n > 0 && matrix[m][n - 1]) q.push({m, n - 1});
          }
          max_found = max(max_found, found);
        }
      }
    }

    cout << "Case #" << (i+1) << ": " << max_found << endl;
  }
}
