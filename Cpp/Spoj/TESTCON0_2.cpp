#include <iostream>
using namespace std;

int main() {
    long currentLetter;
    string letters = "0123456789ABCDEF";
    char input[32];
    char *endPtr = input;
    cin >> input;
    for (int i = 0; i < 8; ++i) {
        currentLetter = strtol(endPtr, &endPtr, 2);
        cout << currentLetter << endl;
//        cout << letters[currentLetter];
    }
    cout << endl;
    return 0;
}
