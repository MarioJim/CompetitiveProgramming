#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        for (int l = 0; l < 9; ++l) {
            string s;
            cin >> s;
            for (char & i : s)
                if (i == '1')
                    i = '2';
            cout << s << endl;
        }
    }
}