#include <iostream>

using namespace std;

int main() {
    long a, b, counter = 0;
    cin >> a >> b;
    while (a != b) {
        if (a < b) {
            counter += b - a;
            break;
        }
        if (a % 2 == 1) {
            ++a;
            ++counter;
        }
        a /= 2;
        ++counter;
    }
    cout << counter << endl;
}