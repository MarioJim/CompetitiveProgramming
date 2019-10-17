#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<unordered_set<string>> citiesForest;

int cityTreeThatIncludesCity(string city) {
    for (int i = 0; i < citiesForest.size(); ++i)
        if (citiesForest[i].find(city) != citiesForest[i].end())
            return i;
    return -1;
}

int main() {
    int numProfs;
    cin >> numProfs;
    for (int i = 0; i < numProfs; ++i) {
        int numCities;
        cin >> numCities;
        unordered_set<string> citiesTree;
        string city;
        int treeToAddTo = -1;
        for (int j = 0; j < numCities; ++j) {
            cin >> city;
            citiesTree.insert(city);
            if (treeToAddTo == -1)
                treeToAddTo = cityTreeThatIncludesCity(city);
        }
        if (treeToAddTo != -1)
            citiesForest[treeToAddTo].insert(citiesTree.begin(), citiesTree.end());
        else
            citiesForest.push_back(citiesTree);
    }
    string from, to;
    cin >> from >> to;
    int indexFrom = -1, indexTo = -1;
    for (int i = 0; i < citiesForest.size(); ++i) {
        if (citiesForest[i].find(from) != citiesForest[i].end())
            indexFrom = i;
        if (citiesForest[i].find(to) != citiesForest[i].end())
            indexTo = i;
    }
    cout << (indexFrom == indexTo ? "posible" : "imposible") << endl;
    return 0;
}
