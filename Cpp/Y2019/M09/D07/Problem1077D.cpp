// http://codeforces.com/problemset/problem/1077/D

#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct queueComparator {
    bool operator() (const tuple<int, int, int> tuple1, const tuple<int, int, int> tuple2) const {
        auto [ key1, frequency1, timesToBeAdded1 ] = tuple1;
        auto [ key2, frequency2, timesToBeAdded2 ] = tuple2;
        return frequency1 / timesToBeAdded1 < frequency2 / timesToBeAdded2;
    }
};

int main() {
    int n, k, num;
    // key, frequency
    map<int, int> keyFreq;
    cin >> n >> k;

    // Add input to keyFreq
    for (int i = 0; i < n; ++i) {
        cin >> num;
        // on keyFreq, add 1 to frequency at key
        keyFreq[num]++;
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, queueComparator> keysToAdd;

    // Add all pairs to keysToAdd
    for (pair<int, int> pairIter : keyFreq)
        keysToAdd.push({ pairIter.first, pairIter.second, 1 });

    while (k > 0) {
        // Pop from keysToAdd
        auto [ key, frequency, timesToBeAdded ] = keysToAdd.top();
        keysToAdd.pop();
        // Add keysToAddTop with times added + 1
        keysToAdd.push({ key, frequency, ++timesToBeAdded });
        // Print key
        cout << key << " ";
        --k;
    }

    return 0;
}
