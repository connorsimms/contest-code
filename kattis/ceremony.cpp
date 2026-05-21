#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  deque<int> v(n);

  for (int i = 0; i < n; ++i)
    cin >> v[i];

  sort(v.begin(), v.end());

  int h = 0;

  int ans = 0;

  while (!v.empty()) {
    if (v.back() - h > v.size()) {
      v.pop_back();
    } else {
      ++h;
      while (v.front() == h)
        v.pop_front();
    }

    ++ans;
  }

  cout << ans << '\n';
}
