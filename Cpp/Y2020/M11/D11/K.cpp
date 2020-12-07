#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define tupiii pair<int, pair<int,int>>

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    auto cmp = [](tupiii left, tupiii right){
        return left.second.first < right.second.first ||
               (left.second.first == right.second.first && left.second.second < right.second.second);
    };
    priority_queue<tupiii, vector<tupiii>, decltype(cmp)> queue(cmp);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        queue.push({i, {a, b}});
    }

    int result[n];
    fill(result, result + n, 0);
    deque<tupiii> remaining;
    int trees[n];
    for (int i = 0; i < n; ++i) trees[i] = i;
    bool finishedSpanningTree = false;
    while (k > 0) {
        if (queue.empty() && remaining.empty()) {
            cout << "Impossible\n";
            return 0;
        }
        tupiii top;
        if (finishedSpanningTree) {
            top = remaining.front();
            remaining.pop_front();
        } else {
            top = queue.top();
            queue.pop();
        }
        if (!finishedSpanningTree)
            for (int i = 0; i < n; ++i) {
                if (trees[i] == trees[top.second.second])
                    trees[i] = trees[top.second.first];
            }
        result[top.second.first]++;
        result[top.second.second]++;
        int firstTree = trees[0];
        if (!finishedSpanningTree)
            finishedSpanningTree = all_of(trees + 1, trees + n, [firstTree](auto i){
                return i == firstTree;
            });
    }
    if (!finishedSpanningTree) {
        cout << "Impossible\n";
        return 0;
    }
    for (int i = 0; i < n - 1; ++i) {
        cout << result[i] << " ";
    }
    cout << result[n - 1] << "\n";
}
