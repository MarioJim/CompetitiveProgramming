#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

int main() {
    int a[] = {1, 3, 3, 5, 5, 5, 7, 7, 7, 7, 7, 9, 9, 9, 9, 9, 9, 9, 9, 11, 11, 11, 11, 11, 11, 11};

    string s;
    getline(cin, s);
    unordered_map<char, int> map;
    for (char i : s) {
        i = tolower(i);
        if (i >= 'a' && i <= 'z')
            ++map[i];
    }
    multimap<int, char, greater<>> mapRev;
    for (pair<char, int> p : map)
        mapRev.insert({p.second, p.first});
    long count = 0, i = 0, countLet = 0;
    for (pair<char, int> p : mapRev) {
        countLet += p.first;
        count += a[i] * p.first;
        ++i;
    }
    count += 3 * (countLet - 1);
    cout << count << endl;
}