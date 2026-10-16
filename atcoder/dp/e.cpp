#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll INF = numeric_limits<ll>::max() / 2;

int main() {
  ll N, W;
  cin >> N >> W;

  ll sumValue{};

  vector<pair<ll, ll>> item;
  for (int i{}; i < N; ++i) {
    ll weight, value;
    cin >> weight >> value;
    item.emplace_back(weight, value);
    sumValue += value;
  }

  vector<vector<ll>> mem(N, vector<ll>(N * 1'000LL + 1, INF));

  // smallest weight to accumulate at least totValue after considering itemId
  auto dp = [&](auto &&rec, int itemId, ll totValue) -> ll {
    totValue = max(totValue, 0LL);
    auto [weight, value] = item[itemId];

    if (itemId == 0) {
      mem[itemId][totValue] = (value >= totValue) ? weight : -1;
    }

    if (totValue == 0) {
      mem[itemId][totValue] = 0;
    }

    if (mem[itemId][totValue] != INF)
      return mem[itemId][totValue];

    auto with = rec(rec, itemId - 1, totValue - value);
    if (with != -1)
      mem[itemId][totValue] = min(mem[itemId][totValue], with + weight);

    auto wout = rec(rec, itemId - 1, totValue);
    if (wout != -1)
      mem[itemId][totValue] = min(mem[itemId][totValue], wout);

    if (mem[itemId][totValue] == INF)
      mem[itemId][totValue] = -1;

    return mem[itemId][totValue];
  };

  ll best = 0, lo = 0, hi = sumValue;
  while (lo <= hi) {
    auto m = (lo + hi) / 2;

    if (dp(dp, N - 1, m) <= W) {
      best = max(best, m);
      lo = m + 1;
    } else {
      hi = m - 1;
    }
  }

  cout << best << '\n';
}
