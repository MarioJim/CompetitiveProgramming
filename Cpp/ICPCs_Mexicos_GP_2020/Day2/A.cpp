#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a ,b;
    cin >> n >> a >> b;
    double prob = 1.0 / (b - a + 1);
    double rolls[n+1];
    fill(rolls, rolls + n + 1, 0.0);
    rolls[a] = 3.512127075052;
    for (int i = a; i < n; ++i) {
        rolls[i+1] = rolls[a];
        for (int j = i - b + 1; j < i - a + 2; ++j) {
            if (j > 0)
                rolls[i+1] += prob * rolls[j];
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "uwu\n";
    cout << fixed << setprecision(10) << rolls[n] << "\n";
}
