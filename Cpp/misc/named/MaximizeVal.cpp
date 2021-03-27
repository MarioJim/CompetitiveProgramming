#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int length;
    cin >> length;
    int nums[length];
    for (int i = 0; i < length; ++i) cin >> nums[i];

    int first[length + 1];
    fill(first, first + length + 1, INT32_MIN);
    for (int i = length - 1; i >= 0; --i) {
        first[i] = max(nums[i], first[i+1]);
    }

    int second[length];
    fill(second, second + length, INT32_MIN);
    for (int i = length - 2; i >= 0; --i) {
        second[i] = max(first[i+1] - nums[i], second[i+1]);
    }

    int third[length - 1];
    fill(third, third + length - 1, INT32_MIN);
    for (int i = length - 3; i >= 0; --i) {
        third[i] = max(second[i+1] + nums[i], third[i+1]);
    }

    int fourth[length - 2];
    fill(fourth, fourth + length - 2, INT32_MIN);
    for (int i = length - 4; i >= 0; --i) {
        fourth[i] = max(third[i+1] - nums[i], fourth[i+1]);
    }

    cout << fourth[0] << endl;
}
