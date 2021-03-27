#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K, tempInput;
    cin >> N >> K;
    vector<pair<int,int>> arr;
    arr.emplace_back(0,1);
    for (int i = 1; i < N; ++i) {
        cin >> tempInput;
        arr.emplace_back(tempInput - 1, 1);
    }
    int result = 0;
    while (K > 0) {
        // Set weights
        for (int i = 1; i < N; ++i)
            if (arr[i].second != 0)
                arr[i].second = arr[arr[i].first].second + 1;
        // Check node with max weight
        int max = 0;
        for (int i = 0; i < N; ++i)
            if (arr[i].second > arr[max].second)
                max = i;
        // Add weight
        result += arr[max].second;
        arr[max].second = 0;
        // Update weights
        while (max != 0) {
            arr[arr[max].first].second = 0;
            max = arr[max].first;
        }
        --K;
    }
    // Print result
    cout << result << "\n";
    return 0;
}
