#include <iostream>
#include <cmath>
#include <tuple>

using namespace std;

int main() {
    int diff;

    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        int a, b, c;
        cin >> a >> b >> c;
        tuple<int,int,int> best = { 0, 0, 0 };
        int bestDiff = INT32_MAX;
        for (int i = 0; i < 100; ++i) {
            for (int j = i; j < 100; j += i) {
                for (int k = j; k < 100; k += j) {
                    diff = abs(a - i) + abs(b - j) + abs(c - k);
                    if (diff < bestDiff) {
                        best = { i, j, k };
                        bestDiff = diff;
                    }
                }
                cout << bestDiff << "\n" << get<0>(best) << " " << get<1>(best) << " " << get<2>(best) << "\n";

            }
            cout << bestDiff << "\n" << get<0>(best) << " " << get<1>(best) << " " << get<2>(best) << "\n";

        }
        cout << bestDiff << "\n" << get<0>(best) << " " << get<1>(best) << " " << get<2>(best) << "\n";
    }
}


