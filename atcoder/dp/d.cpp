#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  int N, W;
  cin >> N >> W;

  vector<pair<ll, ll>> item;
  for (int i{}; i < N; ++i) {
    int weight, value;
    cin >> weight >> value;
    item.emplace_back(weight, value);
  }

  vector<vector<ll>> mem(N, vector<ll>(W + 1, -1));

  auto dp = [&](auto &&rec, int itemId, ll capLeft) -> ll {
    if (itemId == N)
      return 0LL;

    if (mem[itemId][capLeft] != -1)
      return mem[itemId][capLeft];

    auto [weight, value] = item[itemId];

    if (capLeft >= weight) {
      auto with = rec(rec, itemId + 1, capLeft - weight) + value;
      mem[itemId][capLeft] = max(mem[itemId][capLeft], with);
    }

    auto wout = rec(rec, itemId + 1, capLeft);
    mem[itemId][capLeft] = max(mem[itemId][capLeft], wout);

    return mem[itemId][capLeft];
  };

  cout << dp(dp, 0, W) << '\n';
}
