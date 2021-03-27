#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int t = 0; t < n; ++t) {
        string w;
        cin >> w;
        int len;
        cin >> len;
        int counter = 0;
        for (char i : w) {
            if (i >= '0' && i <= '9') {
                int a = i - '0';
                counter = counter * 10 + a;
            } else {
                if (counter == 0) --len;
                else len -= counter;
                counter = 0;
            }
        }
        if (len >= 0) {
            vector<char> newW;
            for (char i : w) {
                if (i >= '0' && i <= '9') {
                    int a = i - '0';
                    counter = counter * 10 + a;
                } else {
                    char x = i;
                    if (counter == 0)
                        counter = 1;
                    for (int j = 0; j < counter; ++j) {
                        newW.push_back(x);
                    }
                    counter = 0;
                }
            }
            for (char i : newW) {
                cout << i;
            }
            cout << "\n";
        } else {
            cout << "unfeasible\n";
        }
    }
}
