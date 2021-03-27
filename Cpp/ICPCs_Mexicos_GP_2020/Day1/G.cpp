#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int pars[18];
    for (int & par : pars) {
        cin >>par;
    }
    string s;
    getline(cin, s);
    int result = 0;
    for (int par : pars) {
        getline(cin, s);
        if (s == "hole in one") {
            result += 1;
        } else if (s == "condor") {
            result += par - 4;
        } else if  (s == "albatross") {
            result += par - 3;
        } else if (s == "eagle") {
            result += par - 2;
        } else if (s == "birdie") {
            result += par - 1;
        } else if (s == "par") {
            result += par;
        } else if (s == "bogey") {
            result += par +1;
        } else if (s == "double bogey") {
            result += par +2;
        } else if (s == "triple bogey") {
            result += par +3;
        }
    }
    cout << result << "\n";
}
