#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> v(n);

  for (int i = 0; i < n; ++i)
    cin >> v[i];

  sort(v.begin(), v.end());

  long long sum = 0;

  for (int i = 0; i < n; ++i)
    sum += v[i];

  cout << max(2 * v.back(), sum) << '\n';
}
