#include <iostream>
#include <functional>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main()
{
  int N, M; cin >> N >> M;

  vector<long long> f(N);

  for (int i = 0; i < N; ++i)
  {
    cin >> f[i];
  }

  sort(f.begin(), f.end(), greater<int>());

  vector<pair<long long,long long>> m;

  for (int i = 0; i < M; ++i)
  {
    int x, p; cin >> x >> p;

    m.emplace_back(x, p);
  }

  sort(m.begin(), m.end(), [](const auto& a, const auto& b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
  });

  long long money = 0;

  for (int i = 0, j = 0; i < f.size() && j < m.size(); )
  {
    auto& [x, p] = m[j];

    money += p * f[i];
    --x;

    if (!x) ++j;
    ++i;
  }

  cout << money << '\n';
}
