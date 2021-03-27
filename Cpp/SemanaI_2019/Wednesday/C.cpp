#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool sushi[n];
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        sushi[i] = temp == 2;
    }
    vector<int> ocurrences;
    ocurrences.push_back(1);
    bool first = sushi[0];
    for (int i = 1; i < n; ++i) {
        if (sushi[i] == first) {
            ++ocurrences[ocurrences.size() - 1];
        } else {
            ocurrences.push_back(1);
            first = sushi[i];
        }
    }
    int maxSize = 0, len = ocurrences.size();
    for (int i = 0; i < len - 1; ++i) {
       if (ocurrences[i] > maxSize && ocurrences[i + 1] > maxSize)
           maxSize = min(ocurrences[i], ocurrences[i + 1]);
    }
    cout << maxSize * 2 <<  endl;
    return 0;
}
