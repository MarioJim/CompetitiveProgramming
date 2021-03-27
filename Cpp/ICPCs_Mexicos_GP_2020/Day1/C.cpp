#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, string> dict;
    for (int i = 0; i < n; ++i) {
        string a, b;
        cin >> a >> b;
        dict[a] = b;
        dict[b] = a;
    }
    string in;
    getline(cin, in);
    getline(cin, in);
    vector<string> res;
    istringstream ss(in);
    string s;
    while (ss >> s) {
        res.push_back(s);
    }
    set<string> visited;
    set<string> changeTo;
    queue<string> queue;
    for (const auto& rs: res) {
        if (visited.find(rs) != visited.end()) continue;
        queue.push(rs);
        while (!queue.empty()) {
            string a = queue.front();
            queue.pop();
            if (changeTo.find(a) != changeTo.end()) continue;
            changeTo.insert(a);
            visited.insert(a);
            auto search = dict.find(a);
            if (search != dict.end()) {
                queue.push(search->second);
                changeTo.insert(search->first);
            }
        }
        auto minel = min_element(changeTo.begin(), changeTo.end(), [](auto a, auto b) {
            if (a.size() == b.size())
                return a < b;
            return a.size() < b.size();
        });
        for (auto it = dict.begin(); it != dict.end(); ++it) {
            if (changeTo.find(it->first) != changeTo.end())
                it->second = *minel;
        }
        changeTo.clear();
    }
    for (auto it = res.begin(); it != res.end(); ++it) {
        if (dict.find(*it) != dict.end()) {
            cout << dict[*it];
        } else {
            cout <<*it;
        }
        if (it == --res.end()) {
            cout << "\n";
        } else {
            cout << " ";
        }
    }
}
