#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;

int main() {
  string a, b;
  cin >> a >> b;

  if (a.size() > b.size())
    swap(a, b);

  vector<vector<int>> mem(a.size() + 1, vector<int>(b.size() + 1, INF));

  for (size_t i{0}; i <= a.size(); ++i) {
    mem[i][0] = i;
  }

  for (size_t j{0}; j <= b.size(); ++j) {
    mem[0][j] = j;
  }

  mem[0][0] = 0;

  for (size_t i{1}; i <= a.size(); ++i) {
    for (size_t j{1}; j <= b.size(); ++j) {
      mem[i][j] = min(mem[i][j], mem[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
      mem[i][j] = min(mem[i][j], mem[i - 1][j] + 1);
      mem[i][j] = min(mem[i][j], mem[i][j - 1] + 1);
    }
  }

  cout << mem.back().back() << '\n';
}
