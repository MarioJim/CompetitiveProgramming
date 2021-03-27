#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    string matches;
    cin >> matches;
    bool sacaLeft = true;
    int left = 0, right = 0;
    int gl = 0, gr = 0;
    for (int i = 0; i < matches.size(); ++i) {
        switch (matches[i]) {
            case 'S':
                if (sacaLeft) ++left;
                else ++right;
                if ((left >= 5 && left >= right + 2) || left == 10) {
                    left = 0; right = 0;
                    gl++;
                } else if ((right >= 5 && right >= left + 2) || right == 10) {
                    left = 0; right = 0;
                    gr++;
                }
                break;
            case 'R':
                sacaLeft = !sacaLeft;
                if (sacaLeft) ++left;
                else ++right;
                if ((left >= 5 && left >= right + 2) || left == 10) {
                    left = 0; right = 0;
                    gl++;
                } else if ((right >= 5 && right >= left + 2) || right == 10) {
                    left = 0; right = 0;
                    gr++;
                }
                break;
            case 'Q':
                if (gl == 2)
                    cout << gl << " (winner) - " << gr << "\n";
                else if (gr == 2)
                    cout << gl << " - " << gr << " (winner)\n";
                else if (sacaLeft)
                    cout << gl << " (" << left << "*) - " << gr << " (" << right << ")\n";
                else
                    cout << gl << " (" << left << ") - " << gr << " (" << right << "*)\n";
                break;
        }
    }
}
