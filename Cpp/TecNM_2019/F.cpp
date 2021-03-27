#include <iostream>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int range, numDevices;
    cin >> range >> numDevices;
    pii devices[numDevices];
    pii cuadrants[4];
    cuadrants[0] = { 0, -1 };
    cuadrants[1] = { -1, 0 };
    cuadrants[2] = { 0, -1 };
    cuadrants[3] = { -1, 0 };

    for (int i = 0; i < numDevices; ++i) {
        int x, y;
        cin >> x >> y;
        devices[i] = { x, y };
        int cuad = -1;
        if (x > 0 && y >= 0) cuad = 0;
        if (x <= 0 && y > 0) cuad = 1;
        if (x < 0 && y <= 0) cuad = 2;
        if (x >= 0 && y < 0) cuad = 3;
        cuadrants[cuad].first = max(cuadrants[cuad].first, abs(x));
        cuadrants[cuad].second = max(cuadrants[cuad].second, abs(y));
    }
    char arr[121][121];
    for (auto & i : arr)
        for (char & j : i)
            j = ' ';
    // Show cuadrant 0
    for (int i = 61; i < 121; ++i)
        for (int j = 60; j < 121; ++j)
            if (i - 60 <= cuadrants[0].first && j - 60 <= cuadrants[0].second)
                arr[i][j] = 'o';
    // Show cuadrant 1
    for (int i = 61; i >= 0; --i)
        for (int j = 61; j < 121; ++j)
            if (60 - i <= cuadrants[1].first && j - 60 <= cuadrants[1].second)
                arr[i][j] = 'o';
    // Show cuadrant 2
    for (int i = 59; i >= 0; --i)
        for (int j = 60; j >= 0; --j)
            if (60 - i <= cuadrants[2].first && 60 - j <= cuadrants[2].second)
                arr[i][j] = 'o';
    // Show cuadrant 3
    for (int i = 60; i < 121; ++i)
        for (int j = 59; j >= 0; --j)
            if (i - 60 <= cuadrants[3].first && 60 - j <= cuadrants[3].second)
                arr[i][j] = 'o';
    arr[60][60] = '#';
    for (int i = 0; i < numDevices; ++i) {
        char toInsert = 'x';
        if (hypot(devices[i].first, devices[i].second) <= range) toInsert = '+';
        arr[devices[i].first + 60][devices[i].second + 60] = toInsert;
    }
    int startX = 60 - max(cuadrants[1].first, cuadrants[2].first);
    int endX = 60 + max(cuadrants[0].first, cuadrants[3].first);
    int startY = 60 - max(cuadrants[0].second, cuadrants[1].second);
    int endY = 60 + max(cuadrants[2].second, cuadrants[3].second);
    for (int i = 120 - startY; i >= 120 - endY; --i) {
        for (int j = startX; j <= endX; ++j)
            cout << arr[j][i];
        cout << '\n';
    }
    return 0;
}
