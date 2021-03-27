#include <iostream>
using namespace std;

int checkIfStartsWith(string* word, string* possibleAction) {
    for (int i = 0; i < word->length(); ++i)
        if (word->at(i) != possibleAction->at(i))
            return -1;
    return (int) possibleAction->at(word->length()) - 'A' + 1;
}

int main() {
    int arrSize;
    cin >> arrSize;
    string inputLine, temp, action;
    for (int i = 0; i < arrSize; ++i) {
        cin >> temp;
        inputLine += temp;
    }
    for (int i = 15; i < inputLine.size(); i += 16)
        if (!(inputLine[i] == 'X' && (inputLine.at(i-1) == 'I' || inputLine.at(i-1) == 'O')))
            action += inputLine[i];
    string triangle = "TRIANGULO", square = "CUADRADO", pyramid = "PIRAMIDE";
    int isTriangle = checkIfStartsWith(&triangle, &action);
    if (isTriangle != -1) {
        for (int i = 0; i < isTriangle; ++i) {
            for (int j = 0; j < i; ++j) cout << '*';
            cout << '\n';
        }
        return 0;
    }
    int isSquare = checkIfStartsWith(&square, &action);
    if (isSquare != -1) {
        for (int i = 0; i < isSquare; ++i) {
            for (int j = 0; j < isSquare; ++j) cout << '*';
            cout << '\n';
        }
        return 0;
    }
    int isPyramid = checkIfStartsWith(&pyramid, &action);
    if (isPyramid != -1) {
        for (int i = 0; i < isPyramid; ++i) {
            for (int j = 0; j < isPyramid - i - 1; ++j) cout << ' ';
            for (int j = 0; j < i * 2 + 1; ++j) cout << '*';
            cout << '\n';
        }
        return 0;
    }
    cout << action << endl;
    return 0;
}
