#include <bits/stdc++.h>
using namespace std;

char getLetter(char a, char b, int k) {
    for (char i = 'A'; i < 'A' + k; ++i)
        if (i != a && i != b)
            return i;
}

int main() {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    if (k == 2) {
        int countStartA = 0, countStartB = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 1 && str[i] == 'A') ++countStartA;
            if (i % 2 == 0 && str[i] == 'B') ++countStartA;
            if (i % 2 == 1 && str[i] == 'B') ++countStartB;
            if (i % 2 == 0 && str[i] == 'A') ++countStartB;
        }
        cout << min(countStartA, countStartB) << "\n";
        if (countStartA < countStartB)
            for (int i = 0; i < n; ++i)
                cout << (i % 2 == 0 ? 'A' : 'B');
        else
            for (int i = 0; i < n; ++i)
                cout << (i % 2 == 1 ? 'A' : 'B');
        cout << endl;
    } else {
        int count2 = 0;
        for (int i = 1; i < n - 1; i += 2) {
            if (str[i] == str[i - 1] || str[i] == str[i + 1]) {
                str[i] = getLetter(str[i - 1], str[i + 1], k);
                ++count2;
            }
        }
        cout << count2 << "\n" << str << endl;
    }
    return 0;
}
