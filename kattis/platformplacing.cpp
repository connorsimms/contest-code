#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
  ll N, S, K;
  cin >> N >> S >> K;

  S *= 2;
  K *= 2;

  vector<ll> pos(N);
  vector<ll> len(N);

  for (int i{}; i < N; ++i) {
    cin >> pos[i];
    pos[i] *= 2;
  }

  if (N == 1) {
    cout << (K >> 1) << endl;
    return 0;
  }

  sort(begin(pos), end(pos));

  bool poss = true;
  int left = -1e9;

  for (int i{}; i < N; ++i) {
    auto p = pos[i];

    if (p - S / 2 < left) // they can touch
    {
      poss = false;
      break;
    }

    left = p + S / 2;
    len[i] = S;
  }

  if (!poss) {
    cout << -1 << '\n';
    return 0;
  }

  // leftmost foundation
  {
    int i = 0;
    auto r_pos = pos[i + 1];
    auto r_len = len[i + 1];
    auto r_bnd = r_pos - r_len / 2;

    auto c_r = pos[i] + len[i] / 2;

    len[i] = min(K, len[i] + (r_bnd - c_r) * 2);
  }

  // process interior foundations
  for (int i{1}; i < N - 1; ++i) {
    auto l_pos = pos[i - 1];
    auto l_len = len[i - 1];
    auto l_bnd = l_pos + l_len / 2;

    auto r_pos = pos[i + 1];
    auto r_len = len[i + 1];
    auto r_bnd = r_pos - r_len / 2;

    auto c_l = pos[i] - len[i] / 2;
    auto c_r = pos[i] + len[i] / 2;

    auto add = min(c_l - l_bnd, r_bnd - c_r) * 2;

    len[i] = min(K, len[i] + add);
  }

  // rightmost foundation
  {
    int i = N - 1;
    auto l_pos = pos[i - 1];
    auto l_len = len[i - 1];
    auto l_bnd = l_pos + l_len / 2;

    auto c_l = pos[i] - len[i] / 2;

    len[i] = min(K, len[i] + (c_l - l_bnd) * 2);
  }

  ll ans{};
  for (auto l : len)
    ans += l;

  cout << (ans >> 1) << '\n';
}

// |------|  |--|  |----| |---|        |------|
