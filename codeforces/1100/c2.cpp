#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;

    deque<ll> v(n);

    for (int i = 0; i < n; ++i)
      cin >> v[i];

    while (!v.empty() && v.back() < 0)
      v.pop_back();

    if (v.empty()) {
    }

    vector<ll> negSum(v.size());

    for (int i = 1; i < v.size(); ++i) {
      negSum[i] += negSum[i - 1];
      if (v[i - 1] < 0)
        negSum[i] += v[i - 1];
    }

    ll best = 0;
    int bestIdx = -1;

    for (int i = 0; i < v.size(); ++i) {
      if (v[i] > 0) {
        ll diff = -1 * negSum[i] - v[i];
        if (diff > best) {
          best = diff;
          bestIdx = i;
        }
      }
    }

    vector<int> ans;

    int flip = 1;
    for (int i = bestIdx - 1; i >= 0; --i) {
      if (v[i] * flip > 0) {
        flip *= -1;
        ans.push_back(i + 1);
      }
    }

    if (bestIdx != -1) {
      ans.push_back(bestIdx + 1);
    }

    cout << ans.size() << '\n';
    for (auto x : ans) {
      cout << x << ' ';
    }

    cout << '\n';
  }
}
