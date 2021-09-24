#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  string f = "facebook";
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int fi = 0;
    for (int j = 0; j < s.length(); ++j) {
      if (s[j] == f[fi]) {
        ++fi;
      }
      if (fi == f.length()) break;
    }
    if (fi == f.length()) {
      cout << "Case #" << (i + 1) << ": YES" << endl;
    } else {
      cout << "Case #" << (i + 1) << ": NO" << endl;
    }
  }
}
