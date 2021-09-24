#include <bits/stdc++.h>

using namespace std;

vector<int> gold;
vector<bool> visited;
vector<set<int>> adjacency_list;

int dfs(int idx) {
  if (visited[idx])
    return INT32_MAX;
  visited[idx] = true;
  int min_gold = gold[idx];
  for (auto &frnd: adjacency_list[idx]) {
    min_gold = min(min_gold, dfs(frnd));
  }
  return min_gold;
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    gold.push_back(tmp);
    visited.push_back(false);
    adjacency_list.emplace_back();
  }

  for (int i = 0; i < m; ++i) {
    int f1, f2;
    cin >> f1 >> f2;
    --f1;
    --f2;
    adjacency_list[f1].insert(f2);
    adjacency_list[f2].insert(f1);
  }

  long long result = 0;
  for (int i = 0; i < n; ++i) {
    if (!visited[i])
      result += dfs(i);
  }

  cout << result << endl;
}
