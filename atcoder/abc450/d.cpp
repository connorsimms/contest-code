#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;

int main() {
  ll N, K;

  cin >> N >> K;

  V<ll> a(N);
  for (int i = 0; i < N; ++i)
    cin >> a[i];

  V<ll> m(N);
  for (int i = 0; i < N; ++i)
    m[i] = a[i] % K;

  sort(m.begin(), m.end());

  ll best = m.back() - m.front();

  for (int i = 0; i < N - 1; ++i) {
    auto diff = m[i] + (K - m[i + 1]);
    best = (diff < best ? diff : best);
  }

  cout << best << '\n';
}
