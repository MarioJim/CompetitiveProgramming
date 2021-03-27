#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int people[n];
    for (int i = 0; i < n; ++i) {
        cin >> people[i];
    }
    int left[n];
    fill(left, left + n, 0);
    int right[n];
    fill(right, right + n, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (people[i] > people [j])
                ++left[i];
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i - 1; j >= 0; --j) {
            if (people[i] > people [j])
                ++right[i];
        }
    }
    long long leftR = 0, bothR = 0;
    for (int i = 0; i < n; ++i) {
        leftR += left[i];
        bothR += min(left[i], right[i]);
    }
    cout << leftR << " " << bothR << "\n";
}
