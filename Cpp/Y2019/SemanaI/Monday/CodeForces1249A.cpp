#include <bits/stdc++.h>
using namespace std;

int main() {
    int q, n;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> n;
        int arr[n];
        for (int j = 0; j < n; ++j)
            cin >> arr[j];
        int bucketSort[101];
        for (int j = 0; j < 101; ++j)
            bucketSort[j] = 0;
        for (int j = 0; j < n; ++j)
            bucketSort[arr[j]]++;
        bool onlyOneTeam = true;
        for (int j = 0; j < 100; ++j)
            if (bucketSort[j] > 0 && bucketSort[j+1] > 0)
                onlyOneTeam = false;
        cout << (onlyOneTeam ? "1" : "2") << endl;
    }
    return 0;
}
