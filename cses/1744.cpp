#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;

int main() {
  int A, B;
  cin >> A >> B;

  vector<vector<int>> mem(A + 1, vector<int>(B + 1, INF));

  auto dp = [&](auto &&rec, int a, int b) {
    if (mem[a][b] != INF)
      return mem[a][b];

    if (a == b)
      return mem[a][b] = 0;

    for (int i{1}; i < a; ++i) {
      mem[a][b] = min(mem[a][b], rec(rec, a - i, b) + rec(rec, i, b) + 1);
    }

    for (int i{1}; i < b; ++i) {
      mem[a][b] = min(mem[a][b], rec(rec, a, b - i) + rec(rec, a, i) + 1);
    }

    return mem[a][b];
  };

  cout << dp(dp, A, B) << '\n';
}
