#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> idx(N + 1);
  for (int i{1}; i <= N; ++i) {
    int x;
    cin >> x;
    idx[x] = i;
  }

  vector<int> a;
  for (int i{1}; i <= N; ++i) {
    int x;
    cin >> x;
    a.push_back(idx[x]);
  }

  size_t best{};
  vector<int> l;

  for (auto i : a) {
    auto it = lower_bound(begin(l), end(l), i);

    if (it == end(l)) {
      l.push_back(i);
    } else {
      *it = i;
    }

    best = max(best, l.size());
  }

  cout << best << '\n';
}
