#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    string num;
    cin >> num;
    for (int i = 1; i <= 9; ++i) {
        int timesDeleted;
        cin >> timesDeleted;
        stack<int> s;
        char digit = i + '0';
        int idx = 0;
        while (idx < num.size() && num[idx] <= digit)
            ++idx;
        cout << digit << " " << num[idx] << " " << idx << "\n";
        int itRight = idx;
        while (timesDeleted > 0) {
            if (num[itRight] == digit) {
                num[itRight] = '#';
                --timesDeleted;
            }
            ++itRight;
        }
        int itLeft = idx;
        while (itLeft >= 0 && timesDeleted > 0) {
            if (num[itLeft] == digit) {
                num[itLeft] = '#';
                --timesDeleted;
            }
            --itLeft;
        }
    }
    for (char i : num)
        if (i != '#')
            cout << i;
    cout << '\n';
}
