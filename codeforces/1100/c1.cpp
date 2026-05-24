#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i)
      cin >> a[i];

    vector<int> ans;

    int flip = 1;

    for (int i = n - 1; i >= 0; --i) {
      if (a[i] * flip > 0) {
        ans.push_back(i + 1);
        flip *= -1;
      }
    }

    cout << ans.size() << '\n';
    for (auto m : ans) {
      cout << m << ' ';
    }
    cout << '\n';
  }
}
