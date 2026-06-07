#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  ull n;
  cin >> n;

  vector<ull> pal = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22};

  for (auto x : pal) {
    if ((n - x) % 12 == 0) {
      cout << x << ' ' << (n - x) << '\n';
      return;
    }
  }
  cout << "-1\n";
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--)
    solve();
}
