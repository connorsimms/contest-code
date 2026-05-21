#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> v(n + 2);

  for (int i = 1; i <= n; ++i)
    cin >> v[i];

  v[0] = v[1];
  v[n + 1] = 0;

  long long m = 100LL;
  int shares = 0;

  for (int i = 1; i <= n; ++i) {
    if (v[i] < v[i + 1]) {
      int vol = min(100'000LL - shares, m / v[i]);
      shares += vol;
      m -= vol * v[i];
    }

    if (v[i] > v[i + 1]) {
      m += shares * v[i];
      shares = 0;
    }
  }

  cout << m << '\n';
}
