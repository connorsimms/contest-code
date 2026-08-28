#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main() {
  vector<int> derange = {1, 0, 1, 2, 9};

  ull n, k;
  cin >> n >> k;
  ull ans{1};

  for (ull i{1}; i <= k; ++i) {
    ull num{1};

    for (ull j{n}; j > n - i; --j) {
      num *= j;
    }

    for (ull j{i}; j >= 1; --j) {
      num /= j;
    }

    num *= derange[i];

    ans += num;
  }

  cout << ans << '\n';
}
