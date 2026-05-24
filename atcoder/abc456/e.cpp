#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int W;

bool test(const vector<vector<int>> &adj, const vector<int> &hday,
          vector<vector<int>> &seen, int idx, int day) {
  if (seen[idx][day] == 1)
    return true;

  if (seen[idx][day] == -1)
    return false;

  int nextDay = (day + 1) % W;

  seen[idx][day] = 1;
  for (auto next : adj[idx]) {
    if (hday[next] & (1 << nextDay)) {
      if (test(adj, hday, seen, next, nextDay))
        return true;
    }
  }

  seen[idx][day] = -1;
  return false;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N);

    for (int i = 0; i < N; ++i)
      adj[i].push_back(i);

    for (int i = 0; i < M; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    cin >> W;

    vector<int> hday(N);

    for (int i = 0; i < N; ++i) {
      string s;
      cin >> s;

      int mask = 0;
      for (int i = 0; i < W; ++i) {
        if (s[i] == 'o') {
          mask |= (1 << i);
        }
      }

      hday[i] = mask;
    }

    vector<vector<int>> seen(N, vector<int>(W));

    bool poss = false;
    for (int i = 0; i < N && !poss; ++i) {
      if (hday[i] & 1) {
        if (test(adj, hday, seen, i, 0))
          poss = true;
      }
    }

    if (poss)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}
