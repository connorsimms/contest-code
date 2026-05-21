#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, X;
  cin >> n >> X;

  vector<int> p(n);
  for (int i = 0; i < n; ++i)
    cin >> p[i];

  sort(p.begin(), p.end());

  int ans = 1;
  int m = X - p[0];

  for (int i = 1; i < n; ++i) {
    if (p[i] <= m) {
      ++ans;
      m = X - p[i];
    } else {
      break;
    }
  }

  cout << ans << '\n';
}
