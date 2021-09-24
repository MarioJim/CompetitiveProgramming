#include <bits/stdc++.h>

using namespace std;

int orientation(std::pair<int,int> &p, std::pair<int,int> &q, std::pair<int,int> &r)
{
  int val = (q.second - p.second) * (r.first - q.first) -
            (q.first - p.first) * (r.second - q.second);
  if (val == 0) return 0;
  return (val > 0)? 1: 2;
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    std::vector<std::pair<int, int>> coords;
    for (int j = 0; j < 4; ++j) {
      int x, y;
      cin >> x >> y;
      coords.emplace_back(x, y);
    }

    int or1 = orientation(coords[1], coords[2], coords[0]);
    int or2 = orientation(coords[2], coords[3], coords[0]);
    int or3 = orientation(coords[3], coords[1], coords[0]);
    if (or1 == or2 && or2 == or3) {
      cout << "Case #" << (i+1) << ": IN" << endl;
    } else {
      cout << "Case #" << (i+1) << ": OUT" << endl;
    }

  }
}
