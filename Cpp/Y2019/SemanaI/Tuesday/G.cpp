#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int damage[n];
    for (int i = 0; i < n; ++i)
        cin >> damage[i];
    string sequence;
    cin >> sequence;
    int minIndex = 0, maxIndex = 0;
    long long result = 0;
    char currentChar = sequence[0];
    for (int i = 0; i < n + 1; ++i) {
        if (currentChar == sequence[i])
            ++maxIndex;
        else {
            sort(damage + minIndex, damage + i, greater<int>());
            for (int j = minIndex; j < i && j - minIndex < k; ++j)
                result += damage[j];
            currentChar = sequence[i];
            minIndex = i;
        }
    }
    cout << result << endl;
    return 0;
}
