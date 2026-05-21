#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
  int T; cin >> T;
  while (T--)
  {
    int N; cin >> N;

    vector<long long> t(N);

    for (int i = 0; i < N; ++i)
    {
      int W; cin >> W;
      for (int j = 0; j < W; ++j)
      {
        int w; cin >> w;
        t[i] += w;
      }
    }

    sort(t.begin(), t.end());

    double ans = 0.0;
    int run = 0;

    for (auto x : t)
    {
      run += x;
      ans += run;
    }

    cout << fixed << setprecision(8) << ans / N << '\n';
  }
}
