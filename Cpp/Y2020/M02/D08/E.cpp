#include <iostream>

using namespace std;

int main() {
    long a;
    cin >> a;
    switch (a % 4) {
        case 0:
            cout << 2 << endl;
            break;
        case 1:
        case 3:
            cout << 0 << endl;
            break;
        case 2:
            cout << 1 << endl;
            break;
    }
}