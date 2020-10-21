#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        int answered;
        cin >> answered;
        int levelsCalled = (answered % 10) - 1;
        int result = levelsCalled * 10 + 1;
        if (answered / 10.0 > 1)
            result += 2;
        if (answered / 100.0 > 1)
            result += 3;
        if (answered / 1000.0 > 1)
            result += 4;
        cout << result << "\n";
    }
}
