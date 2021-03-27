#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, searchingFor, result = 0;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - k; ++i) {
        searchingFor = arr[i] + k;
        if (binary_search(arr.begin(), arr.end(), searchingFor))
            ++result;
    }
    cout << result << endl;
    return 0;
}
