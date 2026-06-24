#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int mx = 0;

  if (s.front() == '1')
    ++mx;
  if (s.back() == '1')
    ++mx;

  int num0 = 0, num1 = 0;
  for (auto x : s) {
    if (x == '1')
      ++num1;
    else
      ++num0;
  }

  for (int i = 1; i < s.size() - 1; ++i) {
    if (s[i] == '1') {
      ++mx;
      continue;
    }

    if (s[i - 1] == '1' && s[i + 1] == '1') {
      s[i] = '1';
      ++mx;
    }
  }

  int mn = mx;

  for (int i = s.size() - 2; i > 0; --i) {
    if (s[i] == '0') {
      continue;
    }

    if (s[i - 1] == '1' && s[i + 1] == '1') {
      s[i] = '0';
      --mn;
    }
  }

  cout << mn << ' ' << mx << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--)
    solve();
}
