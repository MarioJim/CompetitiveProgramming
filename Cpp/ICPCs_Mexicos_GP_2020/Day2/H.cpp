#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    long long weights[n];
    for (int i = 0; i < n; ++i) cin >> weights[i];
    sort(weights, weights + n);
    long long a, b;
    cin >> a >> b;
    int half1Idx = n / 2;
    set<long long> half1 = { 0 };
    for (int i = 0; i < half1Idx; ++i) {
        set<long long> append;
        for (long long it : half1) {
            append.insert(it + weights[i]);
        }
        half1.merge(append);
    }
    long long half1Size = half1.size();
    long long half1Arr[half1Size];
    auto it = half1.begin();
    for (long long i = 0; it != half1.end(); ++i, ++it)
        half1Arr[i] = *it;
    set<long long> half2 = { 0 };
    for (int i = half1Idx; i < n; ++i) {
        set<long long> append;
        for (long long ite : half2) {
            append.insert(ite + weights[i]);
        }
        half2.merge(append);
    }
    long long result = 0;
    for (long long h2 : half2) {
        auto lb = lower_bound(half1Arr, half1Arr + half1Size, a - h2);
        auto ub = upper_bound(half1Arr, half1Arr + half1Size, b - h2);
        result += ub - lb;
    }
    cout << result << "\n";
}
