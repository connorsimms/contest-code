#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; ++i)
      cin >> v[i];

    int md = 0;
    for (int i = 0; i < n - 1; ++i) {
      int d = v[i] - v[i + 1];
      md = max(d, md);
    }

    if (md == 0) {
      cout << "YES\n";
      continue;
    }

    bool poss = true;

    vector<int> s(n, -1);

    for (int i = 0; i < n - 1; ++i) {
      if (v[i] > v[i + 1]) {
        if (s[i] == 1 || s[i + 1] == 0) {
          poss = false;
          break;
        }

        s[i] = 0;
        s[i + 1] = 1;
      }
    }

    if (!poss) {
      cout << "NO\n";
      continue;
    }

    for (int i = 0; i < n - 1; ++i) {
      if (s[i] == 1 && v[i + 1] - v[i] < md) {
        if (s[i + 1] == 0) {
          poss = false;
          break;
        }

        s[i + 1] = 1;
      }
    }

    if (!poss) {
      cout << "NO\n";
      continue;
    }

    for (int i = n - 2; i >= 0; --i) {
      if (s[i + 1] == 0 && v[i + 1] - v[i] < md) {
        if (s[i] == 1) {
          poss = false;
          break;
        }

        s[i] = 0;
      }
    }

    if (!poss) {
      cout << "NO\n";
      continue;
    } else {
      cout << "YES\n";
    }
  }
}
