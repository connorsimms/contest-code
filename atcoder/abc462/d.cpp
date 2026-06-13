#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n, d;
  cin >> n >> d;

  vector<int> ft(1'000'001);

  for (int i = 0; i < n; ++i) {
    int s, t;
    cin >> s >> t;

    if (t - s >= d) {
      for (int j = s; j < ft.size(); j += (j & (-j))) {
        ++ft[j];
      }

      for (int j = t - d + 1; j < ft.size(); j += (j & (-j))) {
        --ft[j];
      }
    }
  }

  ull ans = 0;
  for (int t = 1; t < ft.size(); ++t) {
    ull num = 0;

    for (int i = t; i; i -= (i & (-i))) {
      num += ft[i];
    }

    if (num >= 2) {
      ans += ((num - 1) * num) / 2;
    }
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
