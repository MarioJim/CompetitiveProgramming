#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int counter = n / 100;
    n -= 100 * (n / 100);
    counter += n /20;
    n -= 20 * (n / 20);
    counter += n / 10;
    n -= 10 * (n / 10);
    counter += (n / 5);
    n -= 5 * (n / 5);
    counter += n;
    cout << counter << endl;
    return 0;
}
