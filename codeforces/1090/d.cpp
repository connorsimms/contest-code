#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<long long> v(2 * n);

    for (int i = 0; i < 2 * n; i += 2)
      v[i] = i / 2 + 1;

    for (int i = 1; i < 2 * n; i += 2)
      v[i] = n + i / 2 + 1;

    for (int i = 0; i < n; ++i) {
      cout << v[i] * v[i + 1] << ' ';
    }

    cout << '\n';
  }
}
