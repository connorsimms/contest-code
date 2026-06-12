#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  ll a, b, x;
  cin >> a >> b >> x;

  int lo = 0, hi = log(a) / log(x) + log(b) / log(x) + 2;

  int bestAns = abs(a - b);

  auto test = [&](int m) {
    int ans = 0;

    int ac = a, bc = b;
    for (int i = 0; i < m && ac != bc; ++i) {
      ++ans;
      if (ac < bc)
        bc /= x;
      else
        ac /= x;
    }
    ans += abs(ac - bc);

    bestAns = min(bestAns, ans);

    return ans;
  };

  for (int i = 0; i <= hi + 1; ++i)
    test(i);

  cout << bestAns << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
