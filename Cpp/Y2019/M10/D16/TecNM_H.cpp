#include <iostream>
using namespace std;

int main() {
    int arrSize;
    cin >> arrSize;
    int arr[arrSize];
    for (int i = 0; i < arrSize; ++i) {
        cin >> arr[i];
    }
    int minimum, maximum;
    cin >> minimum >> maximum;
    int result = 0;
    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] <= maximum && arr[i] >= minimum)
            ++result;
    }
    cout << result << endl;
    return 0;
}