#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  ll A, B, X, Y;
  cin >> A >> B >> X >> Y;

  X = abs(X);
  Y = abs(Y);

  auto x = min(X, Y);
  auto y = max(X, Y) - x;
  x *= 2;

  if ((X > Y && A < B) || (X < Y && A > B)) {
    ++x;
    --y;
  }

  ull ans = x * min(A, B);

  ull c1 = (y / 2 + y % 2) * max(A, B) + (y / 2) * min(A, B);
  ull c2 = (y * 2 + y % 2) * min(A, B);

  ans += min(c1, c2);

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--)
    solve();
}
