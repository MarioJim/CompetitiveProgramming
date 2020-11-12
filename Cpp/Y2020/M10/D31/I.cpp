#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string pass;
        cin >> pass;
        int rules = 0;
        if (pass.size() >= 10) ++rules;
        set<char> specialChars = {'.', '#', '$', '%', '/', '(', '&', ')'};
        bool hasCapital = false, hasLower = false, hasSpecial = false, hasNum = false;
        for (char pas : pass) {
            if (pas >= 'A' && pas <= 'Z') hasCapital = true;
            if (pas >= 'a' && pas <= 'z') hasLower = true;
            if (specialChars.find(pas) != specialChars.end()) hasSpecial = true;
            if (pas >= '0' && pas <= '9') hasNum = true;
        }
        if (hasCapital) ++rules;
        if (hasLower) ++rules;
        if (hasSpecial) ++rules;
        for (int j = 0; j < pass.size() - 1; ++j) {
            if (pass[j] >= '0' && pass[j] <= '9' && pass[j+1] >= '0' && pass[j+1] <= '9'){
                int c = max(pass[j] - '0', pass[j+1] - '0');
                int d = min(pass[j] - '0', pass[j+1] - '0');
                if (c == d + 1)
                    hasNum = false;
            }
        }
        if (hasNum) ++rules;
        switch (rules) {
            case 5:
                cout << "Assertion number #" << i+1 <<": Strong\n";
                break;
            case 4:
                cout << "Assertion number #" << i+1 <<": Good\n";
                break;
            case 3:
                cout << "Assertion number #" << i+1 <<": Weak\n";
                break;
            default:
                cout << "Assertion number #" << i+1 <<": Rejected\n";
        }
    }
}
