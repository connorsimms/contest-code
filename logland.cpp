#include <bits/stdc++.h>
using namespace std;

constexpr long long MOD = 1'000'000'007;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int k;
  cin >> k;

  vector<long long> v(k);

  int R = 0;

  for (int i = 0; i < k; ++i)
    cin >> v[i];

  vector<long long> u(k);

  for (int i = 1; i < k; ++i)
    u[i] += (u[i - 1] + v[i - 1]) / 2;

  long long ans = 0;
  long long gap = 0;

  for (int i = k - 1; i >= 0; --i) {
    if (gap >= (1 << 30)) {
      ans += gap;
      gap = 0;
    }

    ans *= 2;
    ans %= MOD;
    gap *= 2;

    auto fill = min(v[i], gap);
    v[i] -= fill;
    gap -= fill;

    if ((v[i] & 1) && gap == 0) {
      if (u[i]) {
        gap += 1;
      } else {
        ++ans;
      }
    }
  }

  ans += gap;
  ans %= MOD;

  cout << ans << '\n';
}
