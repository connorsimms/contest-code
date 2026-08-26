#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<size_t> phi(100001);
  iota(begin(phi), end(phi), 0);

  for (size_t i{2}; i < phi.size(); ++i) {
    if (phi[i] != i)
      continue;

    for (size_t j{i}; j < phi.size(); j += i) {
      phi[j] -= phi[j] / i;
    }
  }

  vector<size_t> pphi(phi);
  for (size_t i{1}; i < pphi.size(); ++i) {
    pphi[i] += pphi[i - 1];
  }

  int t;
  cin >> t;
  for (int c{1}; c <= t; ++c) {
    size_t n;
    cin >> n;

    size_t ans = n * (n + 1) / 2;
    ans -= pphi[n];
    cout << "Case " << c << ": " << ans << '\n';
  }
}
