#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  int n; cin >> n;
  vector<int> t(n);
  for (int i = 0 ; i < n ; ++i)
  {
    cin >> t[i];
  }
  sort(t.rbegin(), t.rend());
  int ans = 0;
  for (int i = 0 ; i < n ; ++i)
  {
    ans = max(t[i] + i + 2, ans);
  }
  cout << ans << '\n';
}
