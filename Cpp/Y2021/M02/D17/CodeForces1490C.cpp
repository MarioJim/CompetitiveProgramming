#include <bits/stdc++.h>

using namespace std;

int main() {
  std::unordered_set<long long> cubes;
  for (long long i = 1; i * i * i < 10000000000000; ++i) {
    cubes.emplace(i*i*i);
  }

  int tests;
  cin >> tests;
  for (int t = 0; t < tests; ++t) {
    long long n;
    cin >> n;
    if (n == 1) {
      cout << "NO\n";
      continue;
    }
    bool found = false;
    long long maxRoot = pow(n, 1 / 3.0) + 1;
    for (long long i = 1; i < maxRoot; ++i) {
      long long b = n - i * i * i;
      auto search = cubes.find(b);
      if (search != cubes.end()) {
        cout << "YES\n";
        found = true;
        break;
      }
    }
    if (!found) {
      cout << "NO\n";
    }
  }
}
