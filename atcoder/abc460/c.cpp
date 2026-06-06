#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int N, M;
  cin >> N >> M;

  vector<int> s(N), n(M);

  for (int i = 0; i < N; ++i)
    cin >> s[i];

  for (int i = 0; i < M; ++i)
    cin >> n[i];

  sort(s.begin(), s.end());
  sort(n.begin(), n.end());

  auto check = [&](int x) {
    int i = N - 1;
    int j = x - 1;
    for (int k = 0; k < x; ++k) {
      if (2 * s[i] >= n[j])
        --i, --j;
      else
        return false;
    }
    return true;
  };

  int l = 0;
  int r = min(M, N);

  int ans = 0;

  while (l <= r) {
    int m = (l + r) / 2;

    if (check(m)) {
      l = m + 1;
      ans = m;
    } else {
      r = m - 1;
    }
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
