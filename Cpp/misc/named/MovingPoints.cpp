#include <iostream>
#include <cmath>

using namespace std;

int n;

double getDistance(double t, const int*x, const int*v) {
    double res = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            res += abs(x[i] + t * v[i] - (x[j] + t * v[j]));
    return res;
}

int main() {
    cin >> n;
    int x[n];
    for (int i = 0; i < n; ++i) cin >> x[i];
    int v[n];
    for (int i = 0; i < n; ++i) cin >> v[i];
    double first = -1000000000, last = 1000000000;
    double firstApp = getDistance(first, x, v), lastApp = getDistance(last, x, v);
    while (true) {
        if (abs(lastApp - firstApp) < numeric_limits<float>::epsilon())
            break;
        if (firstApp > lastApp) {
            first = (first + last) / 2;
            firstApp = getDistance(first, x, v);
        } else {
            last = (first + last) / 2;
            lastApp = getDistance(last, x, v);
        }
    }
    cout << first << " " << last << endl;
    cout << firstApp << " " << lastApp << endl;
    cout << (long long) ceil(firstApp) << endl;
}
