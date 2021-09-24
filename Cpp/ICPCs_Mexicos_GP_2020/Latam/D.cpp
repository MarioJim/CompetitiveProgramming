#include <bits/stdc++.h>
#define LIMIT 100100

using namespace std;

int main() {
  int n;
  cin >> n;

  if (n == 1) {
    cout << "N\n";
    return 0;
  }

  int list[LIMIT];
  fill(list, list + LIMIT, 0);
  for (int i = 0; i < n; ++i) {
    int inp;
    cin >> inp;
    ++list[inp];
  }
  for (int i = 0; i < LIMIT - 1; ++i) {
    int diff = list[i] / 2;
    list[i+1] += diff;
    list[i] -= diff * 2;
  }

  long long sum = 0;
  for (int i : list) {
    sum += i;
  }
  if (sum <= 2) {
    cout << "Y\n";
  } else {
    cout << "N\n";
  }

}
