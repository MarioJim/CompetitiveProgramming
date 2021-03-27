#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    int numDecl, numAssign;
    cin >> numDecl >> numAssign;
    string temp;
    vector<string> identifiers;
    int stillUsing[numDecl];
    getline(cin, temp);
    cout << '\n';
    for (int i = 0; i < numDecl; ++i) {
        getline(cin, temp);
        if (temp[0] == 'I') temp = temp.substr(1);
        temp = temp.substr(7, temp.find('=') - 8);
        cout << temp << endl;
        identifiers.push_back(temp);
        stillUsing[i] = i;
    }
    string from, to;
    for (int i = 0; i < numAssign; ++i) {
        getline(cin, temp);
        if (temp[0] == 'I') temp = temp.substr(1);
        from = temp.substr(0, temp.find('=') - 1);
        to = temp.substr(temp.find('=') + 2, temp.length() - 2);
        cout << "from: " << from << ", to: " << to << endl;
        int indexFrom = find(identifiers.begin(), identifiers.end(), from) - identifiers.begin();
        int indexTo = find(identifiers.begin(), identifiers.end(), to) - identifiers.begin();
        stillUsing[indexFrom] = indexTo;
    }
    unordered_set<int> uniqueIds;
    for (int i = 0; i < numDecl; ++i)
        uniqueIds.insert(stillUsing[i]);
    cout << uniqueIds.size() << '\n';
    return 0;
}
