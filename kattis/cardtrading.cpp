#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, T, K;
  cin >> N >> T >> K;

  vector<int> f(T);

  for (int i = 0; i < N; ++i) {
    int c;
    cin >> c;
    ++f[c - 1];
  }

  vector<pair<long long, long long>> t;

  long long p = 0;

  for (int i = 0; i < T; ++i) {
    long long b, s;

    cin >> b >> s;

    long long vb = b * (2 - f[i]);
    long long vs = s * f[i];

    p -= vb; // buy everything

    t.emplace_back(vb, vs);
  }

  sort(t.begin(), t.end(), [](const auto &a, const auto &b) {
    if (a.first + a.second == b.first + b.second)
      return a.second > b.second;
    return a.first + a.second > b.first + b.second;
  });

  for (int i = 0; i < T - K; ++i) {
    auto &[vb, vs] = t[i];
    p += vb + vs;
  }

  cout << p << '\n';
}
