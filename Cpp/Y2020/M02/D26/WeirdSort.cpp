#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        int n, m;
        cin >> n >> m;
        int a[n];
        for (int j = 0; j < n; ++j) cin >> a[j];
        bool p[n];
        fill(p, p + n, false);
        for (int i = 0; i < m; ++i) {
            int tmp;
            cin >> tmp;
            p[tmp - 1] = true;
        }
        bool can = true;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (a[j] > a[j+1]) {
                    if (p[j]) {
                        int tmp = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = tmp;
                    } else {
                        can = false;
                        break;
                    }
                }
            }
            if (!can) break;
        }
        if (can)
            cout <<"YES\n";
        else
            cout << "NO\n";
    }
}

//int main() {
//    int t;
//    cin >> t;
//    for (int i = 0; i < t; ++i) {
//        int n, m;
//        cin >> n >> m;
//        int a[n];
//        for (int j = 0; j < n; ++j) cin >> a[j];
//        int aCopy[n];
//        for (int j = 0; j < n; ++j) aCopy[j] = a[j];
//
//        set<int> p;
//        for (int j = 0; j < m; ++j) {
//            int tmp;
//            cin >> tmp;
//            p.insert(tmp);
//        }
//
//        set<int> neededSwaps;
//        for (int j = 0; j < n; ++j) {
//            int minim = min(aCopy[j], a[j]), maxim = max(aCopy[j], a[j]);
//            for (int k = minim; k < maxim; ++k)
//                neededSwaps.insert(k);
//        }
//        bool pValid = true;
//        for (int n : neededSwaps) {
//            cout << n << endl;
//            if (p.find(n) == p.end())
//                pValid = false;
//        }
//        if (pValid)
//            cout << "YES\n";
//        else
//            cout << "NO\n";
//    }
//}
