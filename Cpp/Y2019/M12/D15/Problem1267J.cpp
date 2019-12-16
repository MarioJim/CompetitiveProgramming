#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

int ceil(int x, int y) {
    return x / y + (x % y > 0);
}

bool works(unordered_map<int, int>& setFrequencies, int size) {
    for (auto & it : setFrequencies)
        if (it.second % size != 0 && size - (it.second % size) > ceil(it.second, size))
            return false;
    return true;
}

int main() {
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        int n;
        cin >> n;
        unordered_map<int, int> mapAppFreq; // maps app to frequency
        for (int i = 0; i < n; ++i) {
            int c;
            cin >> c;
            ++mapAppFreq[c];
        }
        int lowerFreq = INT32_MAX;
        for (auto & it : mapAppFreq)
            lowerFreq = min(lowerFreq, it.second);
        int maxSize = lowerFreq + 1; // lower frequency
        while (true) {
            if (works(mapAppFreq, maxSize))
                break;
            --maxSize;
        }
        long long totalScreens = 0;
        for (auto & it : mapAppFreq)
            totalScreens += ceil(it.second, maxSize);
        cout << totalScreens << endl;
    }
    return 0;
}