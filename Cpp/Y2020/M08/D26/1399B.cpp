#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        int n;
        cin >> n;
        int candy[n];
        for (int i = 0; i < n; ++i)
            cin >> candy[i];
        int oranges[n];
        for (int i = 0; i < n; ++i)
            cin >> oranges[i];
        int min_candy = *min_element(candy, candy + n);
        int min_oranges = *min_element(oranges, oranges + n);
        long long result = 0;
        for (int i = 0; i < n; ++i)
            result += max(candy[i] - min_candy, oranges[i] - min_oranges);
        cout << result << "\n";
    }
}
