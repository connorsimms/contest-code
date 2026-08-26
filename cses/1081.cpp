#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> f(1000001);
  int n;
  cin >> n;

  int mx{};
  for (int i{}; i < n; ++i) {
    int x;
    cin >> x;
    ++f[x];
    mx = max(x, mx);
  }

  for (int i{mx}; i > 0; --i) {
    int cnt{};

    for (int j{i}; j <= mx && cnt < 2; j += i) {
      cnt += f[j];
    }

    if (cnt >= 2) {
      cout << i << '\n';
      break;
    }
  }
}
