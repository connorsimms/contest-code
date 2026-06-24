#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n;
  cin >> n;

  vector<int> v(n + 1);

  vector<bool> seen(n + 1);

  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }

  for (int i = 1; i <= n; ++i) {
    if (seen[i])
      continue;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int j = i; j <= n; j *= 2) {
      pq.push(v[j]);
    }

    for (int j = i; j <= n; j *= 2) {
      seen[j] = true;
      v[j] = pq.top();
      pq.pop();
    }
  }

  bool isSorted = true;
  for (int i = 1; i <= n; ++i) {
    if (v[i] < v[i - 1])
      isSorted = false;
  }

  if (isSorted)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
