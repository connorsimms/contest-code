#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  int n, k;
  cin >> n >> k;

  unordered_map<int, long long> sum;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    sum[x] += x;
  }

  priority_queue<ll, vector<ll>, greater<ll>> pq;

  for (auto [v, s] : sum) {
    pq.push(s);
  }

  ll ans = 0;

  int sz = pq.size();

  for (int i = 0; i < sz - k; ++i) {
    ans += pq.top();
    pq.pop();
  }

  cout << ans << '\n';
}
