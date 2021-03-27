#include <bits/stdc++.h>

using namespace std;

int main() {
  set<int> primes;
  for (int i = 2; i < 3162; ++i) {
    bool isPrime = true;
    for (int p: primes) {
      if (i % p == 0)
        isPrime = false;
    }
    if (isPrime)
      primes.insert(i);
  }

  int tests;
  cin >> tests;
  for (int t = 0; t < tests; ++t) {
    int a, b;
    cin >> a >> b;
    int gcd_ab = gcd(a, b);
    a /= gcd_ab;
    b /= gcd_ab;

    unordered_set<int> s;
    for (int p : primes) {
      if (p > a) break;
      if (a % p == 0) {
        s.insert(p);
        while (a % p == 0)
          a /= p;
      }
    }
    if (a != 1) s.insert(a);

    for (int p : primes) {
      if (p > b) break;
      if (b % p == 0) {
        s.insert(p);
        while (b % p == 0)
          b /= p;
      }
    }
    if (b != 1) s.insert(b);

    for (int p : primes) {
      if (p > gcd_ab) break;
      if (gcd_ab % p == 0) {
        s.insert(p);
        while (gcd_ab % p == 0)
          gcd_ab /= p;
      }
    }
    if (gcd_ab != 1) s.insert(gcd_ab);

    cout << s.size() << endl;
  }
}
