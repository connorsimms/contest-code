#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main()
{
  int n; cin >> n;
  int t = 0; int m = 0;
  vector<pair<int, int>> r;
  for (int i = 0 ; i < n ; ++i)
  {
    int s; cin >> s;
    m = max(s, m);
    t += s;
    r.emplace_back(s, i);
  }

  if (m * 2 > t)
  {
    cout << "impossible\n"; return 0;
  }

  sort(r.rbegin(), r.rend());

  for (int i = 0 ; i < n ; ++i)
  {
    cout << r[i].second + 1<< ' ';
  }
  cout << '\n';

  return 0;
}
