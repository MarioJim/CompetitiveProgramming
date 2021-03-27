#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >>b;
        bool aEven = a%2 ==0, bEven = b%2 == 0;

        if (a == b) cout << 0 << "\n";
        else if (aEven == bEven && a > b) cout << 1 << "\n";
        else if (aEven != bEven && a < b) cout << 1 << "\n";
        else cout << 2 << "\n";
    }
}
