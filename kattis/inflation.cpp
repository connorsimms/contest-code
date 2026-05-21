#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N; cin >> N;

  vector<int> b(N); 
  iota(b.begin(), b.end(), 1);

  vector<int> c(N);
  for (int i = 0; i < N; ++i) { cin >> c[i]; }

  double best = 1.0;

  sort(c.begin(), c.end());

  for (int i = 0; i < N; ++i)
  {
    if (c[i] > b[i]) { cout << "impossible\n"; return 0; }

    best = min(best, double(c[i]) / b[i]);
  }

  cout << best << '\n';

  return 0;
}
