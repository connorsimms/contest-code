#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

ull vtoi(const vector<int> &v) {
  ull res = 0;
  for (auto x : v) {
    if (x == -1)
      continue;
    res *= 10;
    res += x;
  }
  return res;
}

ull diff(const vector<int> &a, const vector<int> &b) {
  ull ai = vtoi(a);
  ull bi = vtoi(b);
  if (ai > bi)
    return ai - bi;
  else
    return bi - ai;
}

void solve() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  vector<int> d(n);
  vector<bool> avail(10);

  vector<int> less(s.size() + 1, -1), a(s.size() + 1, 0),
      greater(s.size() + 1, -1);

  for (int i = 0; i < s.size(); ++i)
    a[i + 1] = s[i] - '0';

  ull ans = numeric_limits<ull>::max();

  ull val = vtoi(a);

  for (int i = 0; i < n; ++i) {
    cin >> d[i];
    avail[d[i]] = true;
    if (val > d[i])
      ans = min(ans, val - d[i]);
    else
      ans = min(ans, d[i] - val);
  }

  int i = 1;
  bool exact = true;
  for (; i < a.size(); ++i) {
    if (exact && avail[a[i]]) {
      less[i] = a[i];
      greater[i] = a[i];
    } else {
      exact = false;
      break;
    }
  }

  if (exact) {
    cout << "0\n";
    return;
  }

  for (int j = i; j < greater.size(); ++j)
    greater[j] = d.front();

  for (int j = i; j < less.size(); ++j)
    less[j] = d.back();

  for (int j = i; j >= 0; --j) {
    if (greater[j] <= a[j]) {
      int best = d.back();
      for (int k = d.size() - 1; k >= 0; --k)
        if (d[k] > a[j])
          best = d[k];

      if (best > a[j]) {
        greater[j] = best;
        break;
      } else {
        greater[j] = d.front();
      }
    } else
      break;
  }

  for (int j = i; j >= 1; --j) {
    if (less[j] >= a[j]) {
      int best = d.front();
      for (int k = 0; k < d.size(); ++k)
        if (d[k] < a[j])
          best = d[k];

      if (best < a[j]) {
        less[j] = best;
        break;
      } else {
        less[j] = d.back();
      }
    } else
      break;
  }

  if (less[1] > a[1])
    less[1] = -1;

  for (auto x : less) {
    if (x != -1) {
      ans = min(ans, diff(a, less));
      break;
    }
  }

  for (auto x : greater) {
    if (x != -1) {
      ans = min(ans, diff(a, greater));
      break;
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
