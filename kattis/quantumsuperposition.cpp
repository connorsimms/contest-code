#include <bits/stdc++.h>
using namespace std;

template <typename T> using V = vector<T>;

void get_edges(V<V<int>> &o, V<pair<int, int>> &e) {
  vector<bool> seen(o.size());
  queue<int> q;
  seen[1] = true;
  q.push(1);
  while (!q.empty()) {
    auto f = q.front();
    q.pop();
    for (auto nxt : o[f]) {
      e.emplace_back(f, nxt);
      if (!seen[nxt]) {
        seen[nxt] = true;
        q.push(nxt);
      }
    }
  }
}

void get_ans(V<V<int>> &o, V<int> &in, V<V<bool>> &mem) {
  mem[1][0] = true;

  queue<int> q;
  q.push(1);

  while (!q.empty()) {
    auto f = q.front();
    q.pop();

    for (auto nxt : o[f]) {
      for (size_t i{}; i < mem[f].size(); ++i) {
        if (mem[f][i]) {
          mem[nxt][i + 1] = true;
        }
      }

      if (--in[nxt] == 0) {
        q.push(nxt);
      }
    }
  }
}

int main() {
  int n1, n2, m1, m2;
  cin >> n1 >> n2 >> m1 >> m2;

  V<V<int>> o1(n1 + 1), o2(n2 + 1);
  for (int i{}; i < m1; ++i) {
    int a, b;
    cin >> a >> b;
    o1[a].push_back(b);
  }

  for (int i{}; i < m2; ++i) {
    int a, b;
    cin >> a >> b;
    o2[a].push_back(b);
  }

  V<pair<int, int>> e1, e2;
  get_edges(o1, e1);
  get_edges(o2, e2);

  for (auto &r : o1)
    r.clear();

  for (auto &r : o2)
    r.clear();

  V<int> in1(n1 + 1), in2(n2 + 1);
  for (auto [a, b] : e1) {
    o1[a].push_back(b);
    ++in1[b];
  }
  for (auto [a, b] : e2) {
    o2[a].push_back(b);
    ++in2[b];
  }

  V<V<bool>> mem1(n1 + 1, V<bool>(m1 + 1)), mem2(n2 + 1, V<bool>(m2 + 1));
  get_ans(o1, in1, mem1);
  get_ans(o2, in2, mem2);

  vector<bool> ans(mem1[n1].size() + mem2[n2].size());

  for (size_t s1{}; s1 < mem1[n1].size(); ++s1) {
    for (size_t s2{}; s2 < mem2[n2].size(); ++s2) {
      if (mem1[n1][s1] && mem2[n2][s2]) {
        ans[s1 + s2] = true;
      }
    }
  }

  int q;
  cin >> q;
  for (int i{}; i < q; ++i) {
    size_t x;
    cin >> x;

    if (x < ans.size() && ans[x])
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}
