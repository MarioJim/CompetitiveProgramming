#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;

  vector<int> contiguous;
  int contig_size = 1;
  char current = s[0];
  for (int i = 1; i < n; ++i) {
    if (current == s[i]) {
      ++contig_size;
    } else {
      contiguous.push_back(contig_size);
      contig_size = 1;
      current = s[i];
    }
  }
  contiguous.push_back(contig_size);

  int max_size = 0;
  int from = 0, to = 0;
  int changed_left = m;
  while (to < s.size()) {
    while (changed_left > 0) {
      if (s[to] == 'a') {
        --changed_left;
      }
      ++to;
    }
    cout << "new to: " << to << endl;
    max_size = max(max_size, to - from);
    cout << "max size: " << max_size << ", to - from: " << to - from << endl;
    while (s[from] == 'a' && changed_left < m) {
      ++from;
      ++changed_left;
    }
    cout << "new from " << from << endl;
  }

  cout << max_size << endl;
}
