#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int red = (int) ceil(2 * n / (double) k);
    int green = (int) ceil(5 * n / (double) k);
    int blue = (int) ceil(8 * n / (double) k);
    cout << red + green + blue << endl;
    return 0;
}
