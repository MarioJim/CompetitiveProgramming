#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int i = 0;
    if (n <= 2) {
        cout << "YES\n";
        return 0;
    }
    while (i + 1 != n && arr[i] < arr[i+1]) {
        ++i;
    }
    while (i + 1 != n && arr[i] == arr[i+1]) {
        ++i;
    }
    while (i + 1 != n && arr[i] > arr[i+1]) {
        ++i;
    }
    if (i + 1 == n)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
