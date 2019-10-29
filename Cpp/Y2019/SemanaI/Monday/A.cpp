#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    pair<int,int> buses[n];
    for (int i = 0; i < n; ++i) {
        cin >> buses[i].first >> buses[i].second;
    }
    int minWait = buses[0].first - t;
    while (minWait < 0) minWait += buses[0].second;
    int indexMinWait = 0;
    for (int i = 1; i < n; ++i) {
        int wait = buses[i].first - t;
        while (wait < 0) wait += buses[i].second;
        if (wait < minWait) {
            minWait = wait;
            indexMinWait = i;
        }
    }
    cout << indexMinWait + 1 << endl;
    return 0;
}

