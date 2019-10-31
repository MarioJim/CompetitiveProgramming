#include <bits/stdc++.h>
using namespace std;

int n, pieces[3];

int bestFor2(int tempN) {
    int result = 0;
    for (int i = tempN; i >= 0; i -= pieces[1]) {
        if (i % pieces[2] == 0)
            return result + i / pieces[2];
        ++result;
    }
    return -1;
}

int main() {
    cin >> n >> pieces[0] >> pieces[1] >> pieces[2];
    sort(pieces, pieces + 3, greater<int>());
    int result = 0;
    int results[n + 1];
    fill(results, results + n + 1, -1);
    for (int i = n; i >= 0; i -= pieces[0]) {
        int canDo = bestFor2(i);
        if (canDo != -1) {
            results[i] = result + canDo;
        }
        ++result;
    }
    cout << *(max_element(results, results + n + 1)) << endl;
    return 0;
}
