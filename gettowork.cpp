#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int C;
  cin >> C;
  for (int c = 1; c <= C; ++c) {
    cout << "Case #" << c << ": ";

    int N, T, E;
    cin >> N >> T >> E;

    vector<int> ans(N + 1);
    vector<int> pop(N + 1);
    vector<pair<int, int>> car;

    for (int i = 0; i < E; ++i) {
      int H, P;
      cin >> H >> P;

      ++pop[H];

      car.emplace_back(P, H);
    }

    sort(car.rbegin(), car.rend());

    for (auto [p, h] : car) {
      if (pop[h] && h != T) {
        pop[h] -= min(pop[h], p);
        ++ans[h];
      }
    }

    bool imp = false;
    for (int i = 1; i <= N; ++i)
      if (pop[i] && i != T)
        imp = true;

    if (imp)
      cout << "IMPOSSIBLE";
    else {
      for (int i = 1; i <= N; ++i)
        cout << ans[i] << ' ';
    }

    cout << '\n';
  }
}
