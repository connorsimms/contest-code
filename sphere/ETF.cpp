#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<size_t> phi(1'000'001);
  iota(phi.begin(), phi.end(), 0);

  phi[0] = 0;
  phi[1] = 1;

  for (size_t i{2}; i < phi.size(); ++i) {
    if (phi[i] != i)
      continue;

    for (size_t j{i}; j < phi.size(); j += i) {
      phi[j] -= phi[j] / i;
    }
  }

  int T;
  cin >> T;
  for (int i{}; i < T; ++i) {
    int n;
    cin >> n;
    cout << phi[n] << '\n';
  }
}
