#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int sums[n];
    sums[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        sums[i] = sums[i-1] + nums[i];
    }
    unordered_map<int, int> mapSums;
    for (int i = 0; i < n; ++i) {
        mapSums[sums[i]]++;
    }
    int result = 0;
    for (auto sumsPair: mapSums) {
        result += sumsPair.second - 1;
    }
    cout << result << endl;
}
