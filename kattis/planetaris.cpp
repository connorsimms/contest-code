#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  int n, a; cin >> n >> a;
  
  vector<int> e(n);

  for (int i = 0; i < n; ++i)
  {
    cin >> e[i];
  }

  sort(e.begin(), e.end());

  int ans = 0;
  for (auto x : e)
  {
    if (x < a)
    {
      ++ans;
      a -= x + 1;
    }
    else break;
  }

  cout << ans << '\n';
}
