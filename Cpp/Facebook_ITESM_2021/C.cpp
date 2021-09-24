#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    std::vector<tuple<int, int>> coords;
    for (int j = 0; j < 4; ++j) {
      int x, y;
      cin >> x >> y;
      coords.push_back({x, y});
    }
    std::sort(coords.begin(),  coords.end());
    for (int j = 0; j < 4; ++j) {
      cout << coords[j][0] << " " << coords[j][1] << endl;
    }



//    cout << "Case #" << (i+1) << ": " << max_found << endl;
  }
}
