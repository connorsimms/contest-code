#include <bits/stdc++.h>
using namespace std;

double get_dist(double x1, double y1, double x2, double y2) {
  auto dx = x1 - x2;
  auto dy = y1 - y2;

  return sqrt((dx * dx) + (dy * dy));
}

int main() {
  int n, e, p;
  cin >> n >> e >> p;

  vector<pair<double, double>> t(n + 1);

  for (int i{1}; i <= n; ++i) {
    double x, y;
    cin >> x >> y;
    t[i].first = x;
    t[i].second = y;
  }

  vector<vector<double>> dist(n + 1, vector<double>(n + 1));
  set<tuple<double, int, int>> edges;

  for (int i{1}; i <= n; ++i) {
    for (int j{i}; j <= n; ++j) {
      if (i == j) {
        dist[i][j] = 0;
        continue;
      }

      dist[i][j] = get_dist(t[i].first, t[i].second, t[j].first, t[j].second);

      edges.emplace(dist[i][j], i, j);
    }
  }

  vector<int> par(n + 1);

  auto find = [&](auto &&rec, int a) -> int {
    if (par[a] == a) {
      return a;
    }

    return par[a] = rec(rec, par[a]);
  };

  auto join = [&](int a, int b) {
    auto A = find(find, a), B = find(find, b);

    if (A != B) {
      par[A] = B;
    }
  };

  iota(begin(par), end(par), 0);

  for (int i{}; i < p; ++i) {
    int id1, id2;
    cin >> id1 >> id2;
    join(id1, id2);
  }

  for (int i{2}; i <= e; ++i) {
    join(1, i);
  }

  double ans = 0;

  for (auto [cost, i, j] : edges) {
    auto I = find(find, i);
    auto J = find(find, j);

    if (I != J) {
      join(I, J);
      ans += cost;
    }
  }

  cout << ans << '\n';
}
