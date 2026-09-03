#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr ull INF = numeric_limits<ull>::max();

int main() {
  string A, B;
  cin >> A >> B;

  vector<ull> a, b;

  for (size_t i{}; i < B.size() - A.size(); ++i)
    a.push_back(0);

  for (auto c : A)
    a.push_back(c - '0');
  for (auto c : B)
    b.push_back(c - '0');

  vector<vector<vector<vector<ull>>>> mem(
      2, vector<vector<vector<ull>>>(
             2, vector<vector<ull>>(2, vector<ull>(b.size(), INF))));

  vector<vector<vector<vector<ll>>>> choice(
      2, vector<vector<vector<ll>>>(
             2, vector<vector<ll>>(2, vector<ll>(b.size(), -1))));

  auto dp = [&](auto &&rec, bool ga, bool sb, bool lz, size_t pos) -> ull {
    if (pos == b.size()) {
      return 1;
    }

    if (mem[ga][sb][lz][pos] != INF)
      return mem[ga][sb][lz][pos];

    mem[ga][sb][lz][pos] = 0;

    for (ull dig{}; dig <= 9; ++dig) {
      if (!sb && dig > b[pos])
        continue;

      if (!ga && dig < a[pos])
        continue;

      bool new_ga = ga || dig > a[pos];
      bool new_sb = sb || dig < b[pos];
      bool new_lz = lz && (dig == 0);

      auto nxt = rec(rec, new_ga, new_sb, new_lz, pos + 1);
      auto mul = new_lz ? 1 : dig;

      if (mem[ga][sb][lz][pos] <= nxt * mul) {
        mem[ga][sb][lz][pos] = nxt * mul;
        choice[ga][sb][lz][pos] =
            (new_ga << 2) | (new_sb << 1) | (new_lz) | (1 << (dig + 3));
      }
    }

    return mem[ga][sb][lz][pos];
  };

  dp(dp, 0, 0, 1, 0);

  size_t cur = 0;
  bool ga = 0, sb = 0, lz = 1;
  vector<int> ans;

  while (cur < b.size()) {
    int c = choice[ga][sb][lz][cur];
    int dig = __builtin_ctz(c >> 3);

    ans.push_back(dig);

    ++cur;

    ga = c & 4;
    sb = c & 2;
    lz = c & 1;
  }

  size_t i{};
  while (i < ans.size() && ans[i] == 0)
    ++i;

  if (i == ans.size()) {
    cout << 0;
  } else {
    while (i < ans.size()) {
      cout << ans[i];
      ++i;
    }
  }

  cout << '\n';
}
