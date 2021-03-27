#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int main() {
    int n;
    cin >> n;
    long long worms[n];
    for (int i = 0; i < n; ++i)
        cin >> worms[i];
    int m;
    cin >> m;
    int juicyWorms[m];
    for (int i = 0; i < m; ++i)
        cin >> juicyWorms[i];
    auto cmp = [](pii left, pii right){ return left.second < right.second; };
    multiset<pii, decltype(cmp), allocator<pii>> wormsByPos(cmp);
    for (int i = 0; i < m; ++i) {
        pair<int, int> juicyWorm = {i, juicyWorms[i]};
        wormsByPos.insert(juicyWorm);
    }
    for (int i = 0; i < n - 1; ++i)
        worms[i + 1] += worms[i];
    int indexes[m];
    int index = 0;
    for (auto it = wormsByPos.begin(); it != wormsByPos.end(); ++it) {
        pii juicyWormPair = *it;
        while (worms[index] < juicyWormPair.second)
            ++index;
        indexes[juicyWormPair.first] = index + 1;
    }
    for (int ind : indexes) {
        cout << ind << "\n";
    }
    return 0;
}
