#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  double prob[n][n];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> prob[i][j];
    }
  }
  double result[n];
  fill(result, result + n, 0);
  result[0] = 1;
  double tmp_res[n];
  for (int i = 0; i < m; ++i) {
    fill(tmp_res, tmp_res + n, 0);
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        tmp_res[j] += prob[k][j] * result[k];
      }
    }
    bool changed = false;
    for (int j = 0; j < n; ++j) {
      if (abs(tmp_res[j] - result[j]) > 0.00001) {
        changed = true;
        copy(tmp_res, tmp_res + n, result);
        break;
      }
    }
    if (!changed) {
      break;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << result[i] << endl;
  }
}
