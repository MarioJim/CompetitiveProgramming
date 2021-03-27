#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int digits[n + 2];
    digits[0] = 0;
    for (int i = 1; i < n + 1; ++i)
        cin >> digits[i];
    digits[n + 1] = 1001;
    int maxCount = 0;
    for (int i = 0; i < n + 1; ++i) {
        for (int j = i + 1; j < n + 2; ++j) {
            if (digits[j] - digits[i] == j - i)
                maxCount = max(maxCount, j - i - 1);
        }
    }
    cout << maxCount << endl;
    return 0;
}
