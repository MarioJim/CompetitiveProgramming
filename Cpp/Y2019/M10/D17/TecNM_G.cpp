#include <iostream>
#include <cmath>
using namespace std;

int main() {
    string text;
    cin >> text;
    bool toEncode = text[0] == 'E' || text[0] == 'e';
    text.erase(text.begin());
    if (toEncode)
        for (char & c : text)
            c = toupper(c);
    string g, c;
    cin >> g >> c;
    int groupSize = stoi(g.substr(1));
    int offset = stoi(c.substr(1));
    if (!toEncode)
        offset *= -1;
    string result;
    for (int i = 0; i < 1 + floor(text.length() / groupSize); ++i) {
        for (int j = (i + 1) * groupSize - 1; j >= i * groupSize ; --j) {
            try {
                result += (char) (text.at(j) + offset);
            } catch (out_of_range &o) {}
        }
    }
    cout << result << '\n';
    return 0;
}

