#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
  int T; cin >> T; string j; getline(cin, j); 
  while (T--)
  {
    getline(cin, j);

    int N; cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; ++i)
    {
      cin >> j;
      cin >> v[i];
    }

    sort(v.begin(), v.end());

    long long ans = 0;
    for (int i = 0; i < N; ++i)
    {
      ans += abs(v[i] - (i+1));
    }

    cout << ans << '\n';
  }
}
