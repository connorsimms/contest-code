#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int x;
  cin >> x;

  vector<int> h(n), s(n);
  for (int i{}; i < n; ++i)
    cin >> h[i];
  for (int i{}; i < n; ++i)
    cin >> s[i];

  vector<ll> mem(x + 1);
  mem[0] = 0;

  for (int i{}; i < n; ++i) {
    for (int j = x; j >= h[i]; --j) {
      mem[j] = max(mem[j], mem[j - h[i]] + s[i]);
    }
  }

  cout << mem[x] << '\n';
}
