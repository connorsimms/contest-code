#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> p;

  for (int i = 0; i <= n; ++i) {
    int x, y;
    cin >> x >> y;
    p.emplace_back(x, y);
  }

  set<tuple<double, int, int, int>> s;

  unordered_map<int, int> l, r;

  auto area = [&](int p1, int p2, int p3) {
    const auto &[x1, y1] = p[p1];
    const auto &[x2, y2] = p[p2];
    const auto &[x3, y3] = p[p3];

    pair<int, int> u(x2 - x1, y2 - y1);
    pair<int, int> v(x3 - x1, y3 - y1);

    return abs(1.0 * u.first * v.second - 1.0 * u.second * v.first) / 2.0;
  };

  l[0] = -1;
  r[0] = 1;
  for (int i = 1; i < n; ++i) {
    s.emplace(area(i - 1, i, i + 1), i - 1, i, i + 1);
    l[i] = i - 1;
    r[i] = i + 1;
  }
  l[n] = n - 1;
  r[n] = -1;

  for (int i = 0; i < n - m; ++i) {
    const auto [A, P1, P2, P3] = *s.begin();

    cout << P2 << '\n';

    int LP = l[P1];
    if (LP != -1)
      s.erase(tuple(area(LP, P1, P2), LP, P1, P2));

    int RP = r[P3];
    if (RP != -1)
      s.erase(tuple(area(P2, P3, RP), P2, P3, RP));

    r[P1] = P3;
    l[P3] = P1;

    s.erase(tuple(area(P1, P2, P3), P1, P2, P3));

    if (LP != -1) {
      s.emplace(area(LP, P1, P3), LP, P1, P3);
      l[P1] = LP;
      r[LP] = l[P3] = P1;
    }

    if (RP != -1) {
      s.emplace(area(P1, P3, RP), P1, P3, RP);
      r[P1] = l[RP] = P3;
      r[P3] = RP;
    }
  }
}
