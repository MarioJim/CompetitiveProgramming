#include <bits/stdc++.h>

using namespace std;

int main() {
  int tests;
  cin >> tests;
  for (int t = 0; t < tests; ++t) {
    string s;
    cin >> s;
    string::size_type nextParty = 0;
    while ((nextParty = s.find("party", nextParty)) != string::npos) {
      s[nextParty + 2] = 'w';
      s[nextParty + 3] = 'r';
      s[nextParty + 4] = 'i';
    }
    cout << s << endl;
  }
}
