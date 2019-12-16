#include <bits/stdc++.h>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;
    for (int test = 0; test < testCases; ++test) {
        int numCities, highways, start, end;
        cin >> numCities >> highways >> start >> end;
        --start; --end;
        int **roads = new int*[numCities];
        for (int i = 0; i < numCities; ++i) {
            roads[i] = new int[numCities];
            fill(roads[i], roads[i] + numCities, -1);
        }
        for (int i = 0; i < highways; ++i) {
            int from, to, length;
            cin >> from >> to >> length;
            --from; --to;
            roads[from][to] = length;
            roads[to][from] = length;
        }
        int *dist = new int[numCities];
        fill(dist, dist + numCities, INT32_MAX);
        dist[start] = 0;
        bool *visited = new bool[numCities];
        fill(visited, visited + numCities, false);
        vector<int> cities;
        sort(cities.begin(), cities.end(), [&dist](int left, int right) {
            return dist[left] < dist[right];
        });
        for (int i = 0; i < numCities; ++i)
            if (i != start)
                cities.push_back(i);
        int dijkstraStart = start;
        while (!cities.empty()) {
            visited[dijkstraStart] = true;
            for (int i = 0; i < numCities; ++i)
                if (roads[dijkstraStart][i] != -1 && !visited[i] && dist[dijkstraStart] != INT32_MAX)
                    dist[i] = min(dist[i], dist[dijkstraStart] + roads[dijkstraStart][i]);
            sort(cities.begin(), cities.end(), [&dist](int left, int right) {
                return dist[left] < dist[right];
            });
            dijkstraStart = cities[0];
            cities.erase(cities.begin());
        }
        if (dist[end] == INT32_MAX) cout << "NONE\n";
        else cout << dist[end] << endl;
        free(dist);
        free(visited);
        free(roads);
    }
    return 0;
}
