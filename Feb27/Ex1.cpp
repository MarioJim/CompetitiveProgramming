#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, count = 0;
    cin >> n >> k;
    int *nums = new int[n];
    for (int i = 0; i < n; i++)
        cin >> *(nums + i);
    sort(nums, nums + n);
    for (int i = 0; i < n - 1; i++)
        if (nums[lower_bound(nums, nums + n, nums[i] + k) - nums] == nums[i] + k)
            count++;
    cout << count << "\n";
    return 0;
}