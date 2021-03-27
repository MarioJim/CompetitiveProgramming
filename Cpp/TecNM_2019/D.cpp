#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

vector<unordered_set<string>> citiesForest;

set<int> cityTreeThatIncludesCity(const string& city) {
    set<int> result;
    for (int i = 0; i < citiesForest.size(); ++i)
        if (citiesForest[i].find(city) != citiesForest[i].end())
            result.insert(i);
    return result;
}

int main() {
    int numProfs;
    cin >> numProfs;
    for (int i = 0; i < numProfs; ++i) {
        int numCities;
        cin >> numCities;
        unordered_set<string> citiesTree;
        string city;
        set<int> citiesToCombine;
        for (int j = 0; j < numCities; ++j) {
            cin >> city;
            citiesTree.insert(city);
            set<int> citiesToCombineCity = cityTreeThatIncludesCity(city);
            citiesToCombine.insert(citiesToCombineCity.begin(), citiesToCombineCity.end());
        }
        if (citiesToCombine.empty())
            citiesForest.push_back(citiesTree);
        else {
            citiesForest[*(citiesToCombine.begin())].insert(citiesTree.begin(), citiesTree.end());
            for (auto it = ++citiesToCombine.begin(); it != citiesToCombine.end(); ++it) {
                citiesForest[*(citiesToCombine.begin())].insert(citiesForest[*it].begin(), citiesForest[*it].end());
                auto tempIt = citiesForest.begin();
                for (int j = 0; j < *it; ++j) ++tempIt;
                citiesForest.erase(tempIt);
            }
        }
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
