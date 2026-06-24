#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;

int main() {
  int N;
  cin >> N;

  V<V<int>> v(N + 1, V<int>(N + 1));

  for (int i = 1; i <= N; ++i)
    for (int j = i + 1; j <= N; ++j)
      cin >> v[i][j];

  bool poss = false;
  for (int i = i; i <= N; ++i)
    for (int j = i + 1; j <= N; ++j)
      for (int k = j + 1; k <= N; ++k)
        if (v[i][j] + v[j][k] < v[i][k])
          poss = true;

  cout << (poss ? "Yes\n" : "No\n");
}
