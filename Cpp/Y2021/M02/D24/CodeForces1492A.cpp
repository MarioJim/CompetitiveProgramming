#include <bits/stdc++.h>

using namespace std;

int main() {
  int tests;
  cin >> tests;
  for (int t = 0; t < tests; ++t) {
    long long p, swimmers[3];
    cin >> p >> swimmers[0] >> swimmers[1] >> swimmers[2];
    long long minTime = INT64_MAX;
    for (long long swimmer : swimmers) {
      long long laps = ceil(p / (double) swimmer);
      long long timeNextSwimmer = laps * swimmer;
      minTime = min(minTime, timeNextSwimmer - p);
    }
    cout << minTime << endl;
  }
}
