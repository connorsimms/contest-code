#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n; cin >> n;
  vector<int> r(n), c(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> r[i] >> c[i];
  }

  sort(r.begin(), r.end());
  sort(c.begin(), c.end());

  long long ans = 0;

  for (int i = 0 ; i < n; ++i)
  {
    ans += abs(r[i] - (i + 1)); 
    ans += abs(c[i] - (i + 1)); 
  }
  
  cout << ans << '\n';
}
