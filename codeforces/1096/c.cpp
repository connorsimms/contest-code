#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> two, thr, six, oth;

    two.reserve(n);
    thr.reserve(n);
    six.reserve(n);
    oth.reserve(n);

    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;

      if (x % 6 == 0)
        six.push_back(x);
      else if (x % 3 == 0)
        thr.push_back(x);
      else if (x % 2 == 0)
        two.push_back(x);
      else
        oth.push_back(x);
    }

    for (auto x : two)
      cout << x << ' ';
    for (auto x : oth)
      cout << x << ' ';
    for (auto x : thr)
      cout << x << ' ';
    for (auto x : six)
      cout << x << ' ';
    cout << '\n';
  }
}
