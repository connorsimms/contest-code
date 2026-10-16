#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;

  vector<vector<int>> mem(S.size(), vector<int>(T.size(), -1));

  vector<vector<tuple<int, int, char>>> par(
      S.size(), vector<tuple<int, int, char>>(T.size()));

  auto dp = [&](auto &&rec, size_t s, size_t t) -> int {
    if (s == S.size() || t == T.size())
      return 0;

    if (mem[s][t] != -1)
      return mem[s][t];

    auto x = rec(rec, s + 1, t);
    if (mem[s][t] < x) {
      par[s][t] = {s + 1, t, '\0'};
      mem[s][t] = x;
    }

    auto y = rec(rec, s, t + 1);
    if (mem[s][t] < y) {
      par[s][t] = {s, t + 1, '\0'};
      mem[s][t] = y;
    }

    if (S[s] == T[t]) {
      auto z = rec(rec, s + 1, t + 1) + 1;
      if (mem[s][t] < z) {
        par[s][t] = {s + 1, t + 1, S[s]};
        mem[s][t] = z;
      }
    }

    return mem[s][t];
  };

  dp(dp, 0, 0);

  string ans{};
  size_t cs{}, ct{};

  while (cs < S.size() && ct < T.size()) {
    auto [ns, nt, ch] = par[cs][ct];
    if (ch)
      ans += ch;
    cs = ns;
    ct = nt;
  }

  cout << ans << '\n';
}
