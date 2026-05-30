#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, p, m;
    cin >> n >> k >> p >> m;

    int winCost;

    priority_queue<int, vector<int>, greater<int>> pq;
    queue<int> q;

    for (int i = 1, j = 1; i <= n; ++i) {
      int c;
      cin >> c;

      if (i == p) {
        winCost = c;
      } else if (j <= k) {
        pq.push(c);
        ++j;
      } else {
        q.push(c);
        ++j;
      }
    }

    bool valid = true;

    for (int i = 0; i < p - k; ++i) {
      if (m < pq.top()) {
        valid = false;
        break;
      }
      m -= pq.top();
      q.push(pq.top());
      pq.pop();
      pq.push(q.front());
      q.pop();
    }

    int ans = 0;

    while (valid && m >= winCost) {
      m -= winCost;
      ++ans;

      for (int i = 0; i < n - k; ++i) {
        if (m < pq.top()) {
          valid = false;
          break;
        }
        m -= pq.top();
        q.push(pq.top());
        pq.pop();
        pq.push(q.front());
        q.pop();
      }
    }

    cout << ans << '\n';
  }
}
