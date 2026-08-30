#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int INF = 1e9;

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i{}; i < n; ++i)
      cin >> a[i];

    vector<vector<int>> mem(2, vector<int>(n, INF));

    mem[0][0] = a[0];
    mem[0][1] = a[0] + a[1];

    for (int i{0}; i < n; ++i) {
      if (i + 1 < n) {
        mem[0][i + 1] = min(mem[0][i + 1], mem[1][i] + a[i + 1]);
        mem[1][i + 1] = min(mem[1][i + 1], mem[0][i]);
      }
      if (i + 2 < n) {
        mem[0][i + 2] = min(mem[0][i + 2], mem[1][i] + a[i + 1] + a[i + 2]);
        mem[1][i + 2] = min(mem[1][i + 2], mem[0][i]);
      }
    }

    cout << min(mem[0].back(), mem[1].back()) << '\n';
  }
}
