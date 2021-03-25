#include <bits/stdc++.h>

using namespace std;

int main() {
  int tests;
  cin >> tests;
  for (int t = 0; t < tests; ++t) {
    int n;
    cin >> n;
    vector<pair<int, int>> indexes;
    for (int i = 1; i <= n; ++i) {
      int tmp;
      cin >> tmp;
      indexes.emplace_back(tmp, i);
    }

    sort(indexes.begin(), indexes.end());

    long long total_sum = 0, last_total_sum = 0;
    for (int i = 0; i < n; ++i) {
      total_sum += indexes[i].first;
    }

    set<int> result;
    auto rev_indexes_it = indexes.rbegin();
    while (rev_indexes_it != indexes.rend()) {
      total_sum -= rev_indexes_it->first;
      ++rev_indexes_it;
      if (total_sum < last_total_sum) {
        break;
      }
      result.insert(rev_indexes_it->second);
      last_total_sum = total_sum;
    }

    auto result_it = result.begin();
    cout << result.size() << '\n' << *result_it;
    ++result_it;
    for (; result_it != result.end(); ++result_it) {
      cout << ' ' << *result_it;
    }
    cout << endl;
  }
}
