#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n, m;
  cin >> n >> m;

  ll ans = 0;

  priority_queue<int> even, odd, evenM, oddM;
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;

    ans += a;

    if (i & 1)
      odd.push(a);
    else
      even.push(a);
  }

  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;

    if (x & 1) {
      if (!odd.empty() && (odd.top() > 0 || oddM.empty())) {
        ans -= odd.top();
        oddM.push(odd.top());
        odd.pop();
      }
    } else {
      if (!even.empty() && (even.top() > 0 || evenM.empty())) {
        ans -= even.top();
        evenM.push(even.top());
        even.pop();
      }
    }
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
