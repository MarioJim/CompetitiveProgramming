#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, k, query;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for (int i = 0; i < k; ++i) {
        cin >> query;
        if (!binary_search(arr.begin(), arr.end(), query)) {
            cout << "-1\n";
            continue;
        }
        auto upper = upper_bound(arr.begin(), arr.end(), query);
        cout << upper - arr.begin() - 1 << "\n";
    }
    return 0;
}
