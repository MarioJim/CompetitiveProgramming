#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, current, max = 0, result = 0;
    cin >> n >> m;
    map<int, int> mapArr;
    for (int i = 0; i < n; ++i) {
        cin >> current;
        if (current > max)
            max = current;
        mapArr[current]++;
    }
    int count = 0;
    while (result < m) {
        count += mapArr[max--];
        result += count;
    }
    cout << max << endl;
    return 0;
}
