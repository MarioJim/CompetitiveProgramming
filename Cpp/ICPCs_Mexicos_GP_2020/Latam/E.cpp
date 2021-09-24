#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  int buildings[n]; // position -> height
  for (int i = 0; i < n; ++i) {
    cin >> buildings[i];
  }

  unsigned result[n];
  fill(result, result  +n, 0);

  stack<int> left, right;
  stack<int> leftCopy[n];
  stack<int> rightCopy[n];
  for (int i = 0; i < n; ++i) {
    while (!left.empty() && buildings[left.top()] < buildings[i]) {
      left.pop();
    }
    leftCopy[i] = left;
    left.push(i);
  }
  for (int i = n - 1; i >= 0; --i) {
    while (!right.empty() && buildings[right.top()] < buildings[i]) {
      right.pop();
    }
    rightCopy[i] = right;
    right.push(i);
  }

  for (int i = 0; i < n; ++i) {
    stack<int>& r = rightCopy[i];
    stack<int>& l = leftCopy[i];
    int res = 0;
    while (!r.empty() && !l.empty()) {
      if (r.empty()) {
        res += l.size();
        break;
      }
      if (l.empty()) {
        res += r.size();
        break;
      }
      int lb = l.top();
      int rb = r.top();
      if (abs(lb - i) > abs(rb - i)) {
        while (!r.empty() && buildings[lb] > buildings[r.top()]) {
          r.pop();
        }
        l.pop();
      } else if (abs(lb - i) < abs(rb - i)) {
        while (!l.empty() && buildings[rb] > buildings[l.top()]) {
          l.pop();
        }
        r.pop();
      } else {
        l.pop();
        r.pop();
        ++res;
      }
      ++res;
    }
    result[i] = res;
  }

  for (int i = 0; i < n - 1; ++i) {
    cout << result[i] << " ";
  }
  cout << result[n - 1] << endl;
}
