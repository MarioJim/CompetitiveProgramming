#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    sort(nums, nums + n);
    int start = 0, end = n - 1, counter = 0;
    while (start != end) {
        if (counter >= 0) {
            counter -= nums[end];
            --end;
        } else if (counter < 0) {
            counter += nums[start];
            ++start;
        }
    }
    if (counter == nums[start])
    cout << counter << "\n";
}