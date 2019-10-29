#include <bits/stdc++.h>
using namespace std;

int main() {
    int b, k;
    cin >> b >> k;
    int digits[k];
    for (int i = 0; i < k; ++i) cin >> digits[i];
    if (b%2 == 0) {
        if (digits[k-1]%2 == 0) cout << "even\n";
        else cout << "odd\n";
    } else {
        int countOdd = 0;
        for (int i = 0; i < k; ++i)
            if (digits[i]%2 == 1)
                ++countOdd;
        if (countOdd%2 == 0) cout << "even\n";
        else cout << "odd\n";
    }
    return 0;
}
