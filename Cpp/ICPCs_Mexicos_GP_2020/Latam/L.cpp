#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, between;
  cin >> n >> between;

  vector<pair<int, int>> activities;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    activities.emplace_back(a, b);
  }

  pair<int,int> least = {0, INT32_MAX};
  for (int i = 0; i < 480; ++i) {
    int current = 0;
    for (int j = 0; j < activities.size(); ++j) {
      auto & activity = activities[j];
      int length = (activity.first - i) % between;
      length += activity.second + 1;
      if (length > 0) {
        current += length / between;
      }
    }
    if (current < least.second) {
      least = { i, current };
    }
  }

  cout << least.first << ' ' << least.second << endl;
}
