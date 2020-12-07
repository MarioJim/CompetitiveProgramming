#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int maxN = 1000000;
    bool primes[maxN];
    fill(primes, primes + maxN, true);
    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= maxN; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= maxN; j += i)
                primes[j] = false;
        }
    }
    string s;
    cin >> s;
    bool found = false;
    int a, b, c;
    sort(s.begin(), s.end());
    do {
        if (s[0] == '0') continue;
        for (int i = 1; i < s.length() - 1; ++i) {
            if (s[i] == '0') continue;
            a = stoi(s.substr(0, i));
            if (!primes[a]) continue;
            for (int j = i + 1; j < s.length(); ++j) {
                if (s[j] == '0') continue;
                b = stoi(s.substr(i, j - i));
                c = stoi(s.substr(j));
                if (primes[b] && primes[c]) {
                    cout << a * b * c << "\n";
                    return 0;
                }
            }
        }
    } while (next_permutation(s.begin(), s.end()));
    cout << "Bob lies\n";
}
