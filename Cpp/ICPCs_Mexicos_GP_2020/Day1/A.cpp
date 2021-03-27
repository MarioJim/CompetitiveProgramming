#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int answerR(unordered_map<int, vector<pair<int, int>>> &heaps, int i, int j) {
    auto it = heaps[i].begin();
    auto end = heaps[i].end();
    while (it != heaps[i].end() && it->second != j) ++it;
    int r = it != heaps[i].end() ? it->first + 1 : 1;
    if (it != end) {
        heaps[i].erase(it);
    }
    heaps[i].emplace_back(r, j);
    push_heap(heaps[i].begin(), heaps[i].end());
    return r;
}

void answerQ(unordered_map<int, vector<pair<int, int>>> &heaps, int i) {
    auto v = heaps[i];
    if (v.empty()) {
        cout << "No info\n";
    } else if (v.size() == 1) {
        cout << v[0].second << "\n";
    } else {
        bool anyAreEqual = false;
        if (v.size() > 1 && v[1].first == v[0].first) anyAreEqual = true;
        if (v.size() > 2 && v[2].first == v[0].first) anyAreEqual = true;
        if (anyAreEqual) {
            cout << "Multiple\n";
        } else {
            cout << v[0].second << "\n";
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    pair<int, int> maxB = {-1, -1};
    int maxBSize = 0;
    unordered_map<int, vector<pair<int, int>>> heaps;
    for (int qi = 0; qi < q; ++qi) {
        char inst;
        cin >> inst;
        int i, j, newSize;
        switch (inst) {
            case 'R':
                cin >> i >> j;
                newSize = answerR(heaps, i, j);
                if (newSize == maxBSize) {
                    maxB = { -1, -1};
                } else if (newSize > maxBSize) {
                    maxBSize = newSize;
                    maxB = {i, j};
                }
                break;
            case 'Q':
                cin >> i;
                answerQ(heaps, i);
                break;
            default:
                if (maxB.first == -1) {
                    cout << "Multiple\n";
                } else {
                    cout << maxB.first << " " << maxB.second << "\n";
                }
        }
    }
}


//5 13
//R 1 2
//Q 1
//Q 4
//R 2 3
//R 3 2
//R 2 3
//Q 2
//B
//        R 1 4
//R 1 5
//R 1 4
//R 1 2
//Q 1
