#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i{}; i < n; ++i)
    cin >> a[i];

  map<int, int> l;

  int mxlen{}, mxelem{};

  for (int i{}; i < a.size(); ++i) {
    auto x = a[i];

    auto nl = l.count(x - 1) ? l[x - 1] + 1 : 1;

    if (l[x] < nl) {
      l[x] = nl;
    }

    if (l[x] > mxlen) {
      mxlen = l[x];
      mxelem = x;
    }
  }

  int cur = mxelem;
  vector<int> ans;
  for (int i{n - 1}; i >= 0; --i) {
    if (a[i] == cur) {
      ans.push_back(i + 1);
      --cur;
    }
  }

  reverse(begin(ans), end(ans));

  cout << ans.size() << '\n';
  for (auto x : ans) {
    cout << x << ' ';
  }
  cout << '\n';
}
