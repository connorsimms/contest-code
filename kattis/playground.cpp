#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n && n != 0) {
    vector<long long> v(n);

    for (int i = 0; i < n; ++i) {
      double r;
      cin >> r;
      v[i] = (long long)(r * 1000 + 0.5);
      v[i] *= 2; // diameter length
    }

    // we really care about connecting diameters in a way
    // that creates some polygon in three dimensions

    sort(v.begin(), v.end());

    vector<long long> s(v);

    for (int i = 1; i < n; ++i)
      s[i] += s[i - 1];

    bool poss = false;

    for (int i = n - 1; !poss && i >= 1; --i)
      if (i == 1)
        poss = v[0] == v[1];
      else if (s[i - 1] >= v[i])
        poss = true;

    if (poss)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
