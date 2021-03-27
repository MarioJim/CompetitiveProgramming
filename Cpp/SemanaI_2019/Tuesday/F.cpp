#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int choices[n];
    for (int i = 0; i < n; ++i)
        cin >> choices[i];
    transform(choices, choices + n, choices, [](const int i){ return abs(i); });
    sort(choices, choices + n);
    long long pairs = 0;
    for (int i = 0; i < n; ++i) {
        int pos = upper_bound(choices, choices + n, 2 * choices[i]) - choices - 1;
        pairs += abs(i - pos);
    }
    cout << pairs << endl;
    return 0;
}
