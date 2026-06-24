#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

constexpr int INF = 1e9 + 1;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n + 1);

  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }

  vector<int> s(v);

  sort(s.begin(), s.end());

  int med = s[s.size() / 2];

  vector<int> sum(n + 1);
  vector<int> numMed(n + 1);

  for (int i = 1; i <= n; ++i) {
    if (v[i] == med)
      ++numMed[i];
    else if (v[i] < med)
      --sum[i];
    else if (v[i] > med)
      ++sum[i];

    sum[i] += sum[i - 1];
    numMed[i] += numMed[i - 1];
  }

  vector<ll> memo(n + 1, -INF);

  auto dp = [&](int end, auto &&self) -> ll {
    if (end == 0)
      return 0LL;

    if (memo[end] != -INF) {
      return memo[end];
    }

    for (int i = end; i >= 1; i -= 2) {
      int numM = numMed[end] - numMed[i - 1];
      int bal = abs(sum[end] - sum[i - 1]);
      if (bal < numM && numM > 0)
        memo[end] = max(memo[end], 1 + self(i - 1, self));
    }

    return memo[end];
  };

  dp(n, dp);

  cout << memo.back() << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
