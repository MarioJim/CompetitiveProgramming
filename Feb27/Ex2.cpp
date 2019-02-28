#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, toSearch, count = 0;
    cin >> n;
    int *nums = new int[n];
    for (int i = 0; i < n; i++)
        cin >> *(nums + i);
    // a * b + c = d (e + f)
    int *numsSet = new int[n * n * n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                numsSet[i * n * n + j * n + k] = nums[i] * nums[j] + nums[k];
    sort(numsSet, numsSet + n * n * n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
            {
                toSearch = nums[i] * (nums[j] + nums[k]);
                if (nums[i] == 0)
                    continue;
                int *low = lower_bound(numsSet, numsSet + n * n * n, toSearch);
                int *up = upper_bound(numsSet, numsSet + n * n * n, toSearch);
                count += up - low;
            }
    cout << count << "\n";
    return 0;
}