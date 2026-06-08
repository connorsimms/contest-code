#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n, x, s;
  cin >> n >> x >> s;
  string p;
  cin >> p;

  unordered_map<char, int> f;
  for (auto c : p)
    ++f[c];

  int l = 0;
  int r = f['A'];

  auto check = [&](int ia) {
    int seated = 0;
    int aSeen = 0;
    int tablesLeft = x;
    ll openChairs = 0;

    for (int i = 0; i < p.size(); ++i) {
      if (tablesLeft > 0) {
        if (p[i] == 'I') {
          --tablesLeft;
          openChairs += s - 1;
          ++seated;
          continue;
        }

        if (p[i] == 'A' && aSeen++ < ia) {
          --tablesLeft;
          openChairs += s - 1;
          ++seated;
          continue;
        }
      }

      if (openChairs > 0) {
        if (p[i] == 'E' || (p[i] == 'A' && aSeen++ >= ia)) {
          ++seated;
          --openChairs;
          continue;
        }
      }
    }

    return seated;
  };

  int ans = 0;
  while (r - l > 20) {
    int m1 = l + (r - l) / 3;
    int m2 = r - (r - l) / 3;

    auto lr = check(m1);
    auto rr = check(m2);
    ans = max(ans, max(lr, rr));

    if (lr < rr)
      l = m1 + 1;
    else
      r = m2 - 1;
  }

  for (int i = l; i <= r; ++i) {
    ans = max(ans, check(i));
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
