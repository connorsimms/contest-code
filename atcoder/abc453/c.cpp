#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n;
  cin >> n;
  vector<ll> l(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i];
    l[i] *= 2;
  }

  int bestAns = 0;

  for (int i = 0; i < (1 << n); ++i) {
    ll pos = 1;
    int ans = 0;

    for (int j = 0; j < n; ++j) {
      ll posBefore = pos;
      if (i & (1 << j)) {
        pos += l[j];
      } else {
        pos -= l[j];
      }
      ll posAfter = pos;

      if (posBefore > 0 != posAfter > 0)
        ++ans;
    }

    bestAns = max(bestAns, ans);
  }

  cout << bestAns << '\n';
}

int main() { solve(); }
