#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        int n;
        cin >> n;
        int nums[n];
        for (int i = 0; i < n; ++i)
            cin >> nums[i];
        sort(nums, nums + n);
        bool yes = true;
        for (int i = 0; i < n - 1; ++i)
            if (nums[i+1] - nums[i] > 1) {
                yes = false;
                break;
            }
        cout << (yes ? "YES\n" : "NO\n");
    }
}
