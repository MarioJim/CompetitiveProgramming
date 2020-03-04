#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int last = 100;
int* arr;
unordered_map<int, int> from_to = {{1, 18}, {7, 18}, {24, 2}, {22, 20}, {13, 6}};

int main() {
    arr = new int[last + 1];
    fill(arr, arr+last+1, INT32_MAX);
    arr[0] = 0;
    for (int i = 1; i <= last; ++i) {
        for (int j = 1; j <= 6; ++j)
            if (i - j >= 0)
                arr[i] = min(arr[i], arr[i-j]+1);
        if (from_to.find(i) != from_to.end()) {
            int to  = from_to[i];
            arr[to] = min(arr[to], arr[i]);
        }
    }
    for (int i = 0; i <= last; ++i) {
        cout << i << ": " << arr[i] << "\n";
    }
}
