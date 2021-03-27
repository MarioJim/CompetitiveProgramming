#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> ws;
    for (int i = 0; i < n; ++i) {
        string a;
        cin >> a;
        ws.push_back(a);
    }
    int trees[n];
    for (int i = 0; i < n; ++i)
        trees[i] = i;
    for (int i = 0; i < n; ++i) {
        if (i != trees[i])
            continue;
        for (int j = i + 1; j < n; ++j) {
            if (j != trees[j])
                continue;
            if (ws[i].length() != ws[j].length())
                continue;
            string temp = ws[i] + ws[i];
            if (temp.find(ws[j]) != string::npos) {
                trees[j] = i;
            }
        }
    }
    set<int> ts;
    for (int i = 0; i < n; ++i) {
        ts.insert(trees[i]);
    }
    cout << ts.size() << endl;
}
