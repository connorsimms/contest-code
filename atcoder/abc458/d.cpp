#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, q;
  cin >> x >> q;

  int ans = x;
  priority_queue<int> lo;
  priority_queue<int, vector<int>, greater<int>> hi;

  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;

    if (a < ans)
      lo.push(a);
    else
      hi.push(a);

    if (b < ans)
      lo.push(b);
    else
      hi.push(b);

    if (lo.size() > hi.size()) {
      hi.push(ans);
      ans = lo.top();
      lo.pop();
    }

    if (lo.size() < hi.size()) {
      lo.push(ans);
      ans = hi.top();
      hi.pop();
    }
    cout << ans << '\n';
  }
}
